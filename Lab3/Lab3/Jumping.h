#pragma once
#include "FiniteStateMachine.h"
#include "State.h"
#include "Falling.h"
class Jumping : public State
{
public:

	Jumping();
	~Jumping();

	void falling(FiniteStateMachine* a);
};

