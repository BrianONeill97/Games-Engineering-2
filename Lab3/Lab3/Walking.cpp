#include "Walking.h"

Walking::Walking()
{
}

Walking::~Walking()
{
}

void Walking::idle(FiniteStateMachine* a)
{
	std::cout << "Walking to Ideling" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Walking::running(FiniteStateMachine* a)
{
	std::cout << "Walking to running" << std::endl;
	a->setCurrent(new Running());
	delete this;
}
