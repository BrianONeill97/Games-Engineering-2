#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "ECS.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void update();

	void processEvents();
	void render();
	void cleanUp();

	bool running() { return isRunning; }


	Entity entity;


	HealthComponent hc;
	HealthSystem hs;
	

private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;


	bool m_exitGame; // control exiting game

};

#endif // !GAME
