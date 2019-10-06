#include "Running.h"

Running::Running()
{

}

Running::~Running()
{
}

void Running::idle(FiniteStateMachine* a)
{
	std::cout << "Running to idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Running::walking(FiniteStateMachine* a)
{
	std::cout << "Running to walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

