#pragma once
#include "FiniteStateMachine.h"
#include "State.h"
#include "Idle.h"
class Climbing : public State
{
public:

	Climbing();
	~Climbing();
	void idle(FiniteStateMachine* a);
};

