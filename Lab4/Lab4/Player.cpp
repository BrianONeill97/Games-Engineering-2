#include "Player.h"

Player::Player()
{
}

Player::~Player()
{

}

void Player::playerInit(SDL_Renderer* renderer)
{
	currentImage = LoadTexture("test.png", renderer);
}

void Player::update()
{

}

void Player::render(SDL_Renderer* renderer)
{

	SDL_RenderCopy(renderer, currentImage, NULL, NULL);
}

SDL_Texture* Player::LoadTexture(std::string file, SDL_Renderer* render)
{
	texture = nullptr;
	surface = IMG_Load(file.c_str()); // load the image

	if (surface == NULL) // if the image does not load correctly
	{
		std::cout << "Error 1" << std::endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(render, surface); // sets the texture from the surface
		if (texture == NULL)
		{
			std::cout << "Error 2" << std::endl;
		}
	}

	SDL_FreeSurface(surface);
	return texture;
}
