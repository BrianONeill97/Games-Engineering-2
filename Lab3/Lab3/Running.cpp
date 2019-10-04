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

