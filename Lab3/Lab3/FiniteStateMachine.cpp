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
		jumpingState = true;
		FSMCheck = "jumping";
		count++;

		if (count >= 300)
		{
			fallAfterJump = true;
			jumpingState = false;
			currentState->stateCheck = 5;
			count = 0;
		}
		
	}
	if (currentState->stateCheck == 1)
	{
		FSMCheck = "walking";
	}
	if (currentState->stateCheck == 3)
	{
		FSMCheck = "climbing";
	}
	if (fallAfterJump == true)
	{
		FSMCheck = "falling";
		falling();
		count++;
		if (count >= 300)
		{
			fallAfterJump = false;
			count = 0;
		}
	}
	return FSMCheck;
}

void FiniteStateMachine::walking()
{
	currentState->walking(this);
}

void FiniteStateMachine::jumping()
{
	currentState->jumping(this);
}

void FiniteStateMachine::climbing()
{
	currentState->climbing(this);
}

void FiniteStateMachine::idle()
{
	currentState->idle(this);
}

void FiniteStateMachine::falling()
{
	currentState->falling(this);
}
