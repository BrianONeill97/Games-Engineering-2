#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine()
{
	currentState = new Idle();
}

FiniteStateMachine::~FiniteStateMachine()
{
}

std::string FiniteStateMachine::getCurrent()
{
	FSMCheck = "";
	if (currentState->stateCheck == 4)
	{
		FSMCheck = "idle";
	}
	if (currentState->stateCheck == 2)
	{
		FSMCheck = "running";
	}
	if (currentState->stateCheck == 1)
	{
		FSMCheck = "walking";
	}
	if (currentState->stateCheck == 3)
	{
		FSMCheck = "climbing";
	}
	return FSMCheck;
}

void FiniteStateMachine::walking()
{
	currentState->walking(this);
}

void FiniteStateMachine::running()
{
	currentState->running(this);
}

void FiniteStateMachine::climbing()
{
	currentState->climbing(this);
}

void FiniteStateMachine::idle()
{
	currentState->idle(this);
}
