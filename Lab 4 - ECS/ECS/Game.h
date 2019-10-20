#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "ECS.h"
#include <string>


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

	Entity *dog = new Entity();
	Entity *cat = new Entity();
	Entity* player = new Entity();
	Entity* alien = new Entity();

	//Health Component
	std::shared_ptr<Component> ptr = std::make_shared<HealthComponent>();

	//Position Component
	std::shared_ptr<Component> ptrPos = std::make_shared<PositionComponent>();



	HealthSystem hs;
	RenderSystem rs;
	AiSystem ai;


private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;


	bool m_exitGame; // control exiting game

};

#endif // !GAME
