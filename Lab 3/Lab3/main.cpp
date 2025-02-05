#include <iostream>
#include <SDL_image.h>
#include <SDL.h>

#include "Game.h"

using namespace std;

#define DEBUG_MSG

using namespace std;
int main(int argc, char* argv[])
{
	DEBUG_MSG("Game Object Created");
	Game* game = new Game();

	//FrameRate Capping 
	const int Fps = 60;
	const int frameDelay = 1000 / Fps;

	Uint32 framestart;
	int frameTime;


	game->init("Lab 3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running() == true)
	{
		framestart = SDL_GetTicks();

		game->processEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - framestart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	

	game->cleanUp();
	return 0;
}