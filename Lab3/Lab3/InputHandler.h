#include <map>
#include <vector>
#include <SDL.h>
#include "Player.h"

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

enum State
{
	PRESSED = true,
	RELEASED = false
};

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Player* player) = 0;
	virtual InputType type() = 0;
};


class InputHandler
{
	private:
		//Pointers to my commands
		Command* Q;
		Command* W;
		Command* E;
		Command* R;

		
		std::map <int, Command*> commands;


		std::map <int, State> state_map;
		std::map <int, Action> action_map;

		bool inputToAction(); // converts the input into an action
		void fillCommands(std::vector<Command*>& command_queue); // fills the commands queue

		void keydown(SDL_Event& event); // checks to see if the key is pressed
		void keyup(SDL_Event& event); // checks if the key is not pressed

		bool is_held(int key); // if the buttons is being held
		bool was_pressed(int key); 

public:
	InputHandler();
	~InputHandler();
	bool generateInputs(std::vector<Command*>& command_queue); // creates the input commands
	void bindings(int key, Command* command); // binds the keys to a command


};

//Classes to call the functions body
class TypeQ : public Command
{
public:
	void execute(Player* player) { player->typeQ(); }
	InputType type() { return STATE; }
};

class TypeW : public Command
{
public:
	void execute(Player* player) { player->typeW(); }
	InputType type() { return STATE; }
};

class TypeE : public Command
{
public:
	void execute(Player* player) { player->typeE(); }
	InputType type() { return STATE; }
};

class TypeR : public Command
{
public:
	void execute(Player* player) { player->typeR(); }
	InputType type() { return STATE; }
};