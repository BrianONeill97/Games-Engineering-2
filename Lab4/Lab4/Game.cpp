
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

	//m_player.playerInit(renderer);

	entity.addComponents(hc);
	hs.addEntity(entity);

}

/// handle user and system events/ input
void Game::processEvents()
{
		//Handles all the inputs

		//update();
		////Here since had an error where no image would render so placed here and it was fixed.
		//render();
}


/// Update the game world
void Game::update()
{
	//Adds to the time and once the time gets to 15 frames the n the animation change, change this depending on the refresh rate of the monitor 
	i++;
	std::cout << i << std::endl;
}

/// draw the frame and then switch bufers
void Game::render()
{
	//Clears image after every frame
	SDL_RenderClear(renderer);

	//Draw here
	//m_player.render(renderer);
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
