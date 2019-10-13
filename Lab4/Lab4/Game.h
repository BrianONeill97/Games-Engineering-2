#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "ECS.h"
#include <string>
#include "Player.h"


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

	SDL_Surface *screenSurface;

	RenderSystem renderSystem;

	Player player;


	//Dog
	Entity dog;
	HealthComponent dogHC;
	PositionComponent dogPC;

	//Cat
	Entity cat;
	HealthComponent catHC;
	PositionComponent catPC;

private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;


	bool m_exitGame; // control exiting game

};

#endif // !GAME
