#include "Falling.h"

Falling::Falling()
{
}

Falling::~Falling()
{
}

void Falling::idle(FiniteStateMachine* a)
{
	std::cout << "Falling to idle" << std::endl;
	std::cout << "Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
