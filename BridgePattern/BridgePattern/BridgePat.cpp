#include <iostream>
#include <vector>

class DrawApi {
public:
	virtual void Draw() = 0;
	virtual void destroy() = 0;
};

class DrawImpl : public DrawApi {
public:
	void Draw() {
		std::cout << "Draw Impl" << std::endl;
	}
	void destroy() {
		std::cout << "Destruction" << std::endl;
	}
};

class Character {
public:
	virtual void Draw() = 0;
	virtual void destroy() = 0;
};

class Player : public Character {
public:
	Player(DrawApi* api) { this->api = api; }
	void Draw() { api->Draw(); }
	void destroy() { api->destroy(), delete api; }

private:
	DrawApi* api;
};

int main()
{
	DrawApi* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();
	character->destroy();
	std::cin.get();
}