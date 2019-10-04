
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

		renderer = SDL_CreateRenderer(window, -1, 0);
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


}

/// handle user and system events/ input
void Game::processEvents()
{
	while (!exit)
	{
		//Handles all the inputs
		exit = inputHandler->generateInputs(commandQueue);
		update();
	}
}


/// Update the game world
void Game::update()
{
	if (commandQueue.empty())
	{
		fsm->idle();
	}
	else while(!commandQueue.empty())
	{
		commandQueue.back()->execute(fsm);
		commandQueue.pop_back();
	}
}

/// draw the frame and then switch bufers
void Game::render()
{
	SDL_RenderClear(renderer);

	//Draw here

	SDL_RenderPresent(renderer);
}

void Game::cleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}

