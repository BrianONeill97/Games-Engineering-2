#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "InputHandler.h"

#include "FiniteStateMachine.h"

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

	SDL_Texture* LoadTexture(std::string file, SDL_Renderer* render);

	FiniteStateMachine *fsm;
	State *state;

private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	//Animated Sprites
	SDL_Texture* currentImage = nullptr;
	SDL_Rect playerRect;
	SDL_Rect playerPos;
	int frameWidth, frameHeight;
	int textureWidth, textureHeight; 
	const int FPS = 165;
	int frameTime = 0;
	int getFrame(int verticalSpriteNumber, int spriteSize);


	bool m_exitGame; // control exiting game

	// InputHandler Variables
	bool exit;
	InputHandler *inputHandler;
	Player* player;

	//Creates the Command Queue
	std::vector<Command*> commandQueue;


};

#endif // !GAME
