#pragma once
#include "FiniteStateMachine.h"
#include <iostream>

//calls the fsm class
class FiniteStateMachine;

class State
{
public:
	//creates a virtual function
	virtual void walking(FiniteStateMachine* a)
	{
		std::cout << "State walking" << std::endl;
	}

	virtual void running(FiniteStateMachine* a)
	{
		std::cout << "State running" << std::endl;
	}

	virtual void climbing(FiniteStateMachine* a)
	{
		std::cout << "State climbing" << std::endl;
	}

	virtual void idle(FiniteStateMachine* a)
	{
		std::cout << "State idle" << std::endl;
	}

};

