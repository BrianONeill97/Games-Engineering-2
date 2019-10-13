#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "SDL.h"
#include <SDL_ttf.h>


class Component
{

};

class Entity
{
	int id;
public:
	Entity() {};
	void addComponents(Component c) { components.push_back(c); }
	void removeComponent(Component c) {  }
	std::vector<Component> getComponents() {return components; }

	// ADD LAbels using SDL_TFF

	SDL_Rect rect;

	Uint8 r = (rand() % 255) + 0;
	Uint8 g = (rand() % 255) + 0;
	Uint8 b = (rand() % 255) + 0;

private:
	std::vector<Component> components;

};


/*
 _____                                            _       
/  __ \                                            | |      
| /  \/ ___  _ __ ___  _ __   ___  _ __   ___ _ __ | |_ ___ 
| |    / _ \| '_ ` _ \| '_ \ / _ \| '_ \ / _ | '_ \| __/ __|
| \__/| (_) | | | | | | |_) | (_) | | | |  __| | | | |_\__ \
 \____/\___/|_| |_| |_| .__/ \___/|_| |_|\___|_| |_|\__|___/
                      | |                                   
                      |_| */                                  

//Components
class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) {}
	
	int getHealth() { return health; }
	void setHealth(int health) { this->health = health; }
	void addHealth(int healing) { this->health = this->health + healing; }
	void damage(int damage) { this->health = this->health - damage; }

private:
	int health;
};

class PositionComponent : public Component
{
private:
	int xPos = 0;
	int yPos = 0;

public:
	int getX() { return xPos; }
	int getY() { return yPos; }

	void setPos(int x, int y) { xPos = x; yPos = y; }

	void move(int x, int y)
	{
		xPos += x;
		yPos += y;
	}

};


 /*
  ____          _                     
/  ___|         | |                    
\ `--. _   _ ___| |_ ___ _ __ ___  ___ 
 `--. | | | / __| __/ _ | '_ ` _ \/ __|
/\__/ | |_| \__ | ||  __| | | | | \__ \
\____/ \__, |___/\__\___|_| |_| |_|___/
        __/ |                          
       |___/   
*/

//Systems
//class HealthSystem
//{
//	std::vector<Entity> entities;
//	std::vector<HealthComponent> healths;
//
//	std::vector<std::string> entityName;
//
//public:
//	void addEntity(Entity e, HealthComponent hc, std::string name) { entities.push_back(e); healths.push_back(hc); entityName.push_back(name); }
//	void update() 
//	{
//		healths.at(0).damage(1);
//		healths.at(1).damage(1);
//
//		for (int i = 0; i < healths.size(); i++)
//		{
//			if (healths.at(i).getHealth() <= 0)
//			{
//				std::cout << entityName.at(i) << " is Dead " << std::endl;
//			}
//			else
//			{
//				std::cout << entityName.at(i) << " Health :  " << healths.at(i).getHealth() << std::endl;
//			}
//		}		
//	}
//};
//
//class PositionSystem
//{
//	std::vector<Entity> entities;
//	std::vector<PositionComponent> Pos;
//	std::vector<std::string> entityName;
//
//
//
//public:
//	void addEntity(Entity e, PositionComponent pc, std::string name) { entities.push_back(e); Pos.push_back(pc); entityName.push_back(name);
//	}
//
//	void update()
//	{
//		Pos.at(0).move(-1, 0);
//
//
//		for (int i = 0; i < Pos.size(); i++)
//		{
//			std::cout << entityName.at(i) << " :  " << " X = " << Pos.at(i).getX() << "," << " Y = " << Pos.at(i).getY() << std::endl;
//		}
//
//
//		//Check if they touching
//		int dist = Pos.at(0).getX() - Pos.at(1).getX();
//		if (dist < 50 && dist > 0)
//		{
//			std::cout << entityName.at(0) << " Is colliding with " << entityName.at(1) << std::endl;
//		}
//		else
//		{
//			std::cout << entityName.at(0) << " Is not colliding with " << entityName.at(1) << std::endl;
//		}
//
//	}
//};

class RenderSystem
{
	std::vector<Entity> entities;
	std::vector<PositionComponent> positions;
	std::vector<std::string> entityName;

public:
	void addEntity(Entity e, PositionComponent pc, std::string name) { entities.push_back(e); positions.push_back(pc); entityName.push_back(name); }



	void init()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i).rect.h = 50;
			entities.at(i).rect.w = 50;

			entities.at(i).rect.x = positions.at(i).getX();
			entities.at(i).rect.y = positions.at(i).getY();

			

		}
		
	}


	void update()
	{
			for (int i = 0; i < positions.size(); i++)
			{
				entities.at(i).rect.x = positions.at(i).getX();
				entities.at(i).rect.y = positions.at(i).getY();
			}
	}

	void draw(SDL_Renderer* render)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			SDL_SetRenderDrawColor(render, entities.at(i).r, entities.at(i).g, entities.at(i).b, 255);
			SDL_RenderFillRect(render, &entities.at(i).rect);
		}
	}
};
