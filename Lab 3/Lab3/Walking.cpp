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
	std::cout << "Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Walking::running(FiniteStateMachine* a)
{
	std::cout << "Walking to running" << std::endl;
	std::cout << "Running" << std::endl;
	a->setCurrent(new Running());
	delete this;
}
