#include "Idle.h"

Idle::Idle()
{
}

Idle::~Idle()
{
}

void Idle::walking(FiniteStateMachine* a)
{
	std::cout << "Walking" << std::endl;
	//sets the current state 
	a->setCurrent(new Walking());
	//when finished being used it is deleted
	delete this;
}

void Idle::running(FiniteStateMachine* a)
{
	std::cout << "Running" << std::endl;
	//sets the current state 
	a->setCurrent(new Running());
	//when finished being used it is deleted
	delete this;
}

void Idle::climbing(FiniteStateMachine* a)
{
	std::cout << "Climbing" << std::endl;
	//sets the current state 
	a->setCurrent(new Climbing());
	//when finished being used it is deleted
	delete this;
}

void Idle::jumping(FiniteStateMachine* a)
{
	std::cout << "jumping" << std::endl;
	//sets the current state 
	a->setCurrent(new Jumping());
	//when finished being used it is deleted
	delete this;

}
