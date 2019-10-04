#pragma once
#include "FiniteStateMachine.h"
#include "State.h"
#include "Idle.h"
class Running : public State
{
public:

	Running();
	~Running();

	void idle(FiniteStateMachine* a);
};

