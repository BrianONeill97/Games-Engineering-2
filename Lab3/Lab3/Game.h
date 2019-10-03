#ifndef GAME
#define GAME

#include <SDL.h>
#include <iostream>

#include "InputHandler.h"

//#include "FSM.h"

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

private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	
	int imAlive = 0;

	bool m_exitGame; // control exiting game

	// InputHandler Variables
	bool exit;
	InputHandler *inputHandler;
	Player* player;

	//Creates the Command Queue
	std::vector<Command*> commandQueue;


};

#endif // !GAME
