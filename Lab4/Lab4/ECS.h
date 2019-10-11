#pragma once
#include <vector>
#include <iostream>

class Component
{

};

class Entity
{
	int id;
public:
	Entity() {};
	void addComponents(Component c) { components.push_back(c); }
	void removeComponent(Component c) { /* TBI */ }

	std::vector<Component> getComponents() { return components; }

private:
	std::vector<Component> components;
};


//Components
class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) {}
	
	int getHealth() { return health; }
	void setHealth(int health) { this->health = health; }

private:
	int health;
};


//Systems
class HealthSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() 
	{
		std::cout << "HealthSystem Update" << std::endl;
	}
};