#pragma once
#include "FiniteStateMachine.h"
#include <iostream>

//calls the fsm class
class FiniteStateMachine;

class State
{
public:
	int stateCheck = 0;

	virtual void walking(FiniteStateMachine* a)
	{
		//std::cout << "State walking" << std::endl;
		stateCheck = 1;
	}

	virtual void jumping(FiniteStateMachine* a)
	{
		//std::cout << "State jumping" << std::endl;
		stateCheck = 2;
	}

	virtual void climbing(FiniteStateMachine* a)
	{
		//std::cout << "State climbing" << std::endl;
		stateCheck = 3;
	}

	virtual void idle(FiniteStateMachine* a)
	{
		//std::cout << "State idle" << std::endl;
		stateCheck = 4;
	}

	virtual void falling(FiniteStateMachine* a)
	{
		//std::cout << "State falling" << std::endl;
		stateCheck = 5;
	}

};

