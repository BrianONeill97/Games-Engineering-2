#include "Player.h"

Player::Player()
{

}

Player::~Player()
{
}

void Player::init(SDL_Renderer* render)
{
	//Player
//Position Component
	pc.setPos(100, 97);
	playerEntity.addComponents(pc);
	//ps.addEntity(playerEntity);
	//Health Component
	playerEntity.addComponents(hc);
	//hs.addEntity(playerEntity);

	rect.h = rectHeight;
	rect.w = rectWidth;
	rect.x = pc.getX();
	rect.y = pc.getY();

}

void Player::update()
{
	pc.setPos(pc.getX() + 1, pc.getX() + 1);

	//Update Player


	rect.x = pc.getX();
	rect.y = pc.getY();

}

void Player::draw(SDL_Renderer* render)
{
	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	SDL_RenderFillRect(render, &rect);
}

