
#include "Game.h"


Game::Game() 
{

}


Game::~Game()
{
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{	
	int flags = 0;

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

	screenSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

	//Dog
	dogPC.setPos(400,200);
	dog.addComponents(dogPC);
	dog.addComponents(dogHC);

	//cat
	catPC.setPos(100, 400);
	cat.addComponents(catPC);	
	cat.addComponents(catHC);

	renderSystem.addEntity(dog, dogPC, "Dog");
	renderSystem.addEntity(cat, catPC, "Cat");

	aiSystem.addEntity(dog, dogPC, dogHC, "Dog");
	aiSystem.addEntity(cat, catPC, catHC, "cat");


	renderSystem.init();	
}

/// handle user and system events/ input
void Game::processEvents()
{
		//Handles all the inputs
}


/// Update the game world
void Game::update()
{
	aiSystem.update();

	renderSystem.update();

	system("CLS");
}

/// draw the frame and then switch bufers
void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//Clears image after every frame
	SDL_RenderClear(renderer);

	//Draw here
	renderSystem.draw(renderer);

	//Presents the new Images
	SDL_RenderPresent(renderer);
}

void Game::cleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	window = nullptr;
	renderer = nullptr;

	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}
