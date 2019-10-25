#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "SDL.h"
#include <string>
#include <typeindex>

static int dogHealth = 60;
static int catHealth = 30;
static int playerHealth = 100;
static int alienHealth = 150;

static int dogX = 700;
static int dogY = 100;

static int catX = 100;
static int catY = 10;

static int playerX = 200;
static int playerY = 200;

static int alienX = 400;
static int alienY = 500;

class Component
{
public:
	int componentId;

	//Here so dynamic pointer cast works
	virtual void getId()
	{
		//Does nothing, should return the id (Didnt get it in in time)
	};
};
// _______ .__   __. .___________. __  .___________.____    ____ 
//|   ____||  \ |  | |           ||  | |           |\   \  /   / 
//|  |__   |   \|  | `---|  |----`|  | `---|  |----` \   \/   /  
//|   __|  |  . `  |     |  |     |  |     |  |       \_    _/   
//|  |____ |  |\   |     |  |     |  |     |  |         |  |     
//|_______||__| \__|     |__|     |__|     |__|         |__|   

class Entity
{
private:
	std::vector<std::shared_ptr<Component>> components;
	int id;

public:
	Entity() {};
	void addComponents( std::shared_ptr<Component> &p) 
	{ 
		components.push_back(p);
	}
	
	void removeComponent(Component c) 
	{ 
		  
	}
	
	std::vector<std::shared_ptr<Component>> getComponent()
	{
		//returns my vector of components so they can be used in systems
		return std::vector<std::shared_ptr<Component>>(components);
	}

	//std::vector < std::shared_ptr<HealthComponent>> getHC()
	//{
	//	return std::vector<std::shared_ptr<HealthComponent>>(healthPtr);
	//}

	SDL_Rect rect;

	Uint8 r = (rand() % 255) + 0;
	Uint8 g = (rand() % 255) + 0;
	Uint8 b = (rand() % 255) + 0;
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
	void damage(int i) { this->health -= 1; }

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
class HealthSystem
{
public:
	std::vector<Entity> entities;
	std::vector<std::string> entityName;
	std::vector<std::shared_ptr<HealthComponent>> healthPtr;



	void addEntity(Entity e, std::string name) { entities.push_back(e); entityName.push_back(name); }

	void init()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.at(i).getComponent().size(); j++)
			{
				if (typeid(*(entities.at(i).getComponent().at(j))) == typeid(HealthComponent))
				{
					//converts from type component to healthComponent at run time.
					healthPtr.push_back(std::dynamic_pointer_cast<HealthComponent>(entities.at(i).getComponent().at(j)));


					healthPtr.at(i) = std::make_shared <HealthComponent>();
				}
				else
				{
					std::cout << "HEALTH COMPONENT IS NOT PRESENT!" << std::endl;
				}
			}
		}

		for (int i = 0; i < entities.size(); i++)
		{
			if (entityName.at(i) == "Dog")
			{
				healthPtr.at(i)->setHealth(dogHealth);
			}
			else if (entityName.at(i) == "Cat")
			{
				healthPtr.at(i)->setHealth(catHealth);
			}
			else if (entityName.at(i) == "Player")
			{
				healthPtr.at(i)->setHealth(playerHealth);
			}
			else if (entityName.at(i) == "Alien")
			{
				healthPtr.at(i)->setHealth(alienHealth);
			}
		}
	}
	void update() 
	{
		for (int i = 0; i < healthPtr.size(); i++)
		{
			std::cout << entityName.at(i) << " Health : " << healthPtr.at(i)->getHealth() << std::endl;
		}
		std::cout <<  ""  << std::endl;
		//healthPtr.at(0)->damage(1);
	}
};


class RenderSystem
{
public:

	std::vector<Entity> entities;
	std::vector<std::string> entityName;
	std::vector<std::shared_ptr<PositionComponent>> PosPtr;

	void addEntity(Entity e, std::string name) { entities.push_back(e); entityName.push_back(name); }

	void init()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.at(i).getComponent().size(); j++)
			{
				if (typeid(*(entities.at(i).getComponent().at(j))) == typeid(PositionComponent))
				{
					PosPtr.push_back(std::dynamic_pointer_cast<PositionComponent>(entities.at(i).getComponent().at(j)));
					PosPtr.at(i) = std::make_shared <PositionComponent>();
				}
				else
				{
					std::cout << "Position Component IS NOT PRESENT!" << std::endl;
				}
			}
		}

		for (int i = 0; i < PosPtr.size(); i++)
		{
			if (entityName.at(i) == "Dog")
			{
				PosPtr.at(i)->setPos(dogX,dogY);
			}
			else if (entityName.at(i) == "Cat")
			{
				PosPtr.at(i)->setPos(catX,catY);
			}
			else if (entityName.at(i) == "Player")
			{
				PosPtr.at(i)->setPos(playerX, playerY);
			}
			else if (entityName.at(i) == "Alien")
			{
				PosPtr.at(i)->setPos(alienX, alienY);
			}
		}

		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i).rect.h = 50;
			entities.at(i).rect.w = 50;

			entities.at(i).rect.x = PosPtr.at(i)->getX();
			entities.at(i).rect.y = PosPtr.at(i)->getY();
		}
	}

	void update()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i).rect.x = PosPtr.at(i)->getX();
			entities.at(i).rect.y = PosPtr.at(i)->getY();
		}

		for (int i = 0; i < PosPtr.size(); i++)
		{
			std::cout << entityName.at(i) << " :  " << " X = " << PosPtr.at(i)->getX() << "," << " Y = " << PosPtr.at(i)->getY() << std::endl;
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

class AiSystem
{
public:
	std::vector<Entity> entities;
	std::vector<std::string> entityName;


	void addEntity(Entity e, std::string name) { entities.push_back(e); entityName.push_back(name); }
	void init()
	{
	}

	void update()
	{

	}

};