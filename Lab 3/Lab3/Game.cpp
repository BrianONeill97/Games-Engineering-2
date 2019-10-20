
#include "Game.h"


Game::Game() 
{
	exit = false;

	//Init InputHandler
	inputHandler = new InputHandler();

	//Creates my Player
	player = new Player();
	fsm = new FiniteStateMachine();
	state = new State();


}


Game::~Game()
{
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	playerPos.x = playerPos.y = 200;
	playerPos.w = playerPos.h = 128; // size of the character
	int flags = 0;

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cout << " ERROR " << IMG_GetError() << std::endl;
	}

	if (fullscreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << " Subsystem initialised!!" << std::endl;
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

		if (window)
		{
			std::cout << "Window Created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0 | SDL_RENDERER_PRESENTVSYNC);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;

		}

		isRunning = true;

	}
	else
	{
		isRunning = false;
	}

	//Loads the image
	currentImage = LoadTexture("spritesheet.png", renderer);

	//Used for animation
	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

	frameWidth = textureWidth / 13;
	frameHeight = textureHeight / 21;

	//Start of the animation of on the horizontal 
	playerRect.x = 0;
	//Width and height of the frames of tha animation
	playerRect.w = frameWidth;
	playerRect.h = frameHeight;
}

/// handle user and system events/ input
void Game::processEvents()
{
		//Handles all the inputs
		inputHandler->generateInputs(commandQueue);

		//update();
		////Here since had an error where no image would render so placed here and it was fixed.
		//render();
}


/// Update the game world
void Game::update()
{
	//Adds to the time and once the time gets to 15 frames the n the animation change, change this depending on the refresh rate of the monitor 
	frameTime++;
	if (FPS / frameTime == 11)
	{
		frameTime = 0;
		playerRect.x += frameWidth;

		//WRAPS it around
		if (playerRect.x >= textureWidth)
		{
			playerRect.x = 0;
		}
	}


	if (commandQueue.empty() &&  fsm->fallAfterJump == false && fsm->jumpingState == false)
	{
			fsm->idle();
	}
	else while(!commandQueue.empty())
	{
		commandQueue.back()->execute(fsm);
		commandQueue.pop_back();
	}

	//Checking the current state of the player
	if (fsm->getCurrent() == "idle")
	{
		playerRect.y = getFrame(2, 64); // changes the x to the different animation
		//WRAPS it around since there is white space, if there isnt any then this is uncesscary
		if (playerRect.x >= 448)
		{
			playerRect.x = 0;
		}
	}

	if (fsm->getCurrent() == "climbing")
	{
		playerRect.y = getFrame(17,64);
	}

	if (fsm->getCurrent() == "walking")
	{
		
		playerRect.y = getFrame(9, 64);
		//WRAPS it around since there is white space, if there isnt any then this is uncesscary
		if (playerRect.x >= 448)
		{
			playerRect.x = 0;
		}
		
	}

	if (fsm->getCurrent() == "jumping")
	{
		playerRect.y = getFrame(19, 64);

	}

	if (fsm->getCurrent() == "falling")
	{
		playerRect.y = getFrame(4, 64);
		//WRAPS it around since there is white space, if there isnt any then this is uncesscary
		if (playerRect.x >= 448)
		{
			playerRect.x = 0;
		}
	}

}

/// draw the frame and then switch bufers
void Game::render()
{
	//Clears image after every frame
	SDL_RenderClear(renderer);

	//Draw here
	SDL_RenderCopy(renderer, currentImage, &playerRect, &playerPos);

	//Presents the new Images
	SDL_RenderPresent(renderer);
}

void Game::cleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(currentImage);

	window = nullptr;
	renderer = nullptr;
	currentImage = nullptr;

	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}

SDL_Texture* Game::LoadTexture(std::string file, SDL_Renderer* render)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = IMG_Load(file.c_str()); // load the image

	if (surface == NULL) // if the image does not load correctly
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(render, surface); // sets the texture from the surface
		if (texture == NULL)
		{
			std::cout << "Error" << std::endl;
		}
	}

	SDL_FreeSurface(surface);
	return texture;
}

int Game::getFrame(int verticalSpriteNumber, int spriteSize)
{
	int pos = verticalSpriteNumber * spriteSize;
	return pos;
}

