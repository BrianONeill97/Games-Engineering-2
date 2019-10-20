#include "Jumping.h"

Jumping::Jumping()
{
}

Jumping::~Jumping()
{
}

void Jumping::falling(FiniteStateMachine* a)
{
	std::cout << "Jumping to falling" << std::endl;
	std::cout << "Falling" << std::endl;
	a->setCurrent(new Falling());
	delete this;
}
