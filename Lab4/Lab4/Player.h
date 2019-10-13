#pragma once

#include "ECS.h"
#include "SDL.h"
#include "SDL_image.h"

class Player
{
public:
	Player();
	~Player();

	void init(SDL_Renderer* render);
	void update();
	void draw(SDL_Renderer* render);

	SDL_Rect rect;
	int rectWidth = 50;
	int rectHeight = 50;

	Uint32 color;

	//Player
	Entity playerEntity;
	HealthComponent hc;
	PositionComponent pc;


};

