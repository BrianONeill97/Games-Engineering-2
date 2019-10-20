#include <map>
#include <vector>
#include <SDL.h>
#include "Player.h"
#include "FiniteStateMachine.h"

enum InputType
{
	ACTION,
	STATE,
	RANGE
};

enum Action
{
	EXECUTE = true,
	STOP = false
};

enum inputState
{
	PRESSED = true,
	RELEASED = false
};

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(FiniteStateMachine* fsm) = 0;
	virtual InputType type() = 0;
};


class InputHandler
{
	private:
		//Pointers to my commands
		Command* Climbing;
		Command* Jumping;
		Command* Walking;
		Command* Idle;
		Command* Falling;

		
		std::map <int, Command*> commands;


		std::map <int, inputState> state_map;
		std::map <int, Action> action_map;

		bool inputToAction(); // converts the input into an action
		void fillCommands(std::vector<Command*>& command_queue); // fills the commands queue

		void keydown(SDL_Event& event); // checks to see if the key is pressed
		void keyup(SDL_Event& event); // checks if the key is not pressed

		bool was_pressed(int key); 

public:
	InputHandler();
	~InputHandler();
	bool generateInputs(std::vector<Command*>& command_queue); // creates the input commands
	void bindings(int key, Command* command); // binds the keys to a command
	bool is_held(int key); // if the buttons is being held


};

//Classes to call the functions body
//Execution of States Changing
class Climb : public Command
{
public:
	void execute(FiniteStateMachine* fsm) { fsm->climbing(); }
	InputType type() { return STATE; }
};

class Jump : public Command
{
public:
	void execute(FiniteStateMachine* fsm) { fsm->jumping(); }
	InputType type() { return STATE; }
};

class Walk : public Command
{
public:
	void execute(FiniteStateMachine* fsm) { fsm->walking(); }
	InputType type() { return STATE; }
};

class Standing : public Command
{
public:
	void execute(FiniteStateMachine* fsm) { fsm->idle(); }
	InputType type() { return STATE; }
};

class Fall : public Command
{
public:
	void execute(FiniteStateMachine* fsm) { fsm->falling(); }
	InputType type() { return STATE; }
};