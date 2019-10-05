#pragma once
#include <iostream>
#include <chrono>
#include <thread>

#include "Idle.h"

//calls class state
class State;

class FiniteStateMachine
{
public:
	FiniteStateMachine();
	~FiniteStateMachine();
	//sets the current state
	class State* currentState;

	void setCurrent(State* s){currentState = s;}
	//Gets the current state by placing int valeus in the states function for each state and the comparing them against a string (always lower case one word of the action e.g walking,shootingup)
	std::string getCurrent();

	//makes functions
	void walking();
	void running();
	void climbing();
	void idle();

	std::string FSMCheck;


};

