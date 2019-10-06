#pragma once
#include "FiniteStateMachine.h"
#include "State.h"
#include "Idle.h"
class Walking : public State
{
public:

	Walking();
	~Walking();
	void idle(FiniteStateMachine* a);
	void running(FiniteStateMachine* a);

};

