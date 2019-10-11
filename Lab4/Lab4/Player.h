#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
class Player
{
public:

	Player();
	~Player();

	void playerInit(SDL_Renderer* renderer);
	void update();
	void render(SDL_Renderer* renderer);

	SDL_Texture* currentImage = nullptr;

	SDL_Texture* LoadTexture(std::string file, SDL_Renderer* render);

	SDL_Texture* texture;
	SDL_Surface* surface;
	SDL_Rect playerRect;
	SDL_Rect playerPos;

};

