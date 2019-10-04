#pragma once
#include <iostream>
#include <chrono>
#include <thread>

#include "Idle.h"

//calls class state
class State;

class FiniteStateMachine
{
	class State* currentState;

public:
	FiniteStateMachine();
	~FiniteStateMachine();
	//sets the current state
	void setCurrent(State* s){currentState = s;}

	//makes functions
	void walking();
	void running();
	void climbing();
	void idle();
};

