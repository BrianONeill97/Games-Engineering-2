#pragma once
#include "FiniteStateMachine.h"
#include "State.h"
#include "Idle.h"
class Falling : public State
{
public:

	Falling();
	~Falling();

	void idle(FiniteStateMachine* a);
};

