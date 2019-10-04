#include "Climbing.h"

Climbing::Climbing()
{

}

Climbing::~Climbing()
{
}

void Climbing::idle(FiniteStateMachine* a)
{
	std::cout << "Climbing to idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

