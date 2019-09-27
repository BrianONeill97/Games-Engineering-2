#include <iostream>
#include <vector>
// creates a base for the objects 
class Character
{
public:
	Character(){}
	virtual ~Character() {}
	virtual void draw() = 0;
	virtual void destroy() = 0;
};

// alllows for new derived types of the base class without having to rely on a concrete class
class Player : public Character
{
public: 
	void draw() {
		std::cout << "Draw Player" << std::endl;
	}

	void destroy() {
		std::cout << "Delete Player" << std::endl; delete this;
	}
};
// allows for interchaging of implementation without changing the code that they use
class Boss : public Character {
public:
	void draw() {
		std::cout << "Draw Boss" << std::endl;
	}

	void destroy() {
		std::cout << "Delete Boss" << std::endl; delete this;
	}
};

class Factory {
public:
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateOpponents() = 0;

};

class CharacterFactory : public Factory
{
public:
	Character* CreatePlayer() {
		return new Player;
	}

	Character* CreateOpponents() {
		return new Boss;
	}
};

int main()
{
	Factory* factory = new CharacterFactory;
	std::vector<Character*> characters;
	characters.push_back(factory->CreatePlayer());

	characters.push_back(factory->CreateOpponents());


	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}

	characters[0]->destroy();


}