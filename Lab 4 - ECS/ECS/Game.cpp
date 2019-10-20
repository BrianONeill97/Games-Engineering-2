
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


	//Dog
	dog->addComponents(ptr);
	dog->addComponents(ptrPos);
	//Cat
	cat->addComponents(ptr);
	cat->addComponents(ptrPos);
	//Player
	player->addComponents(ptr);
	player->addComponents(ptrPos);
	//Alien
	alien->addComponents(ptr);
	alien->addComponents(ptrPos);

	hs.addEntity(*dog,"Dog");
	hs.addEntity(*cat, "Cat");
	hs.addEntity(*player, "Player"); 
	hs.addEntity(*alien, "Alien");

	rs.addEntity(*dog, "Dog");
	rs.addEntity(*cat, "Cat");
	rs.addEntity(*player, "Player");
	rs.addEntity(*alien, "Alien");

	ai.addEntity(*dog, "Dog");
	ai.addEntity(*cat, "Cat");
	ai.addEntity(*player, "Player");
	ai.addEntity(*alien, "Alien");

	hs.init();
	rs.init();
	ai.init();
}

/// handle user and system events/ input
void Game::processEvents()
{
		//Handles all the inputs
}


/// Update the game world
void Game::update()
{
	hs.update();
	rs.update();
	ai.update();

	system("CLS");
}

/// draw the frame and then sitch bufers
void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//Clears image after every frame
	SDL_RenderClear(renderer);

	//Draw here
	rs.draw(renderer);

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
