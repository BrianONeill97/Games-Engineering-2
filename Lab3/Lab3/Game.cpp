
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
	playerPos.x = playerPos.y = 0;
	playerPos.w = playerPos.h = 128;
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

	currentImage = LoadTexture("spritesheet.png", renderer);

	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

	frameWidth = textureWidth / 13;
	frameHeight = textureHeight / 21;

	playerRect.x = 0;
	playerRect.w = frameWidth;
	playerRect.h = frameHeight;
}

/// handle user and system events/ input
void Game::processEvents()
{
	while (!exit)
	{
		//Handles all the inputs
		exit = inputHandler->generateInputs(commandQueue);
		update();
		render();

	}
}


/// Update the game world
void Game::update()
{

	frameTime++;
	if (FPS / frameTime == 11)
	{
		frameTime = 0;
		playerRect.x += frameWidth;

		if (playerRect.x >= textureWidth)
		{
			playerRect.x = 0;
		}
	}


	if (commandQueue.empty())
	{
		fsm->idle();
	}
	else while(!commandQueue.empty())
	{
		commandQueue.back()->execute(fsm);
		commandQueue.pop_back();
	}

	if (fsm->getCurrent() == "idle")
	{
		playerRect.y = getFrame(20, 64);
	}

	if (fsm->getCurrent() == "climbing")
	{
		playerRect.y = getFrame(17,64);
	}

	if (fsm->getCurrent() == "walking")
	{
		playerRect.y = getFrame(6, 64);
	}

	if (fsm->getCurrent() == "running")
	{
		playerRect.y = getFrame(18, 64);
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
	SDL_Surface* surface = IMG_Load(file.c_str());

	if (surface == NULL)
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(render, surface);
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

