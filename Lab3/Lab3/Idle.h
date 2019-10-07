#pragma once
#include "FiniteStateMachine.h"
#include "State.h"
#include "Climbing.h"
#include "Running.h"
#include "Walking.h"
#include "Jumping.h"

class Idle : public State
{
public:
	Idle();
	~Idle();
	void walking(FiniteStateMachine* a);
	void running(FiniteStateMachine* a);
	void climbing(FiniteStateMachine* a);	
	void jumping(FiniteStateMachine* a);

};

