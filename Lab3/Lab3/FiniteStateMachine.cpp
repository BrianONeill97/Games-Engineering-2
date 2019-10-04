#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine()
{
	currentState = new Idle();
}

FiniteStateMachine::~FiniteStateMachine()
{
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
