#include "InputHandler.h"

InputHandler::InputHandler()
{
	//Creates pointers to all the commands
	Climbing = new Climb();
	Jumping = new Jump();
	Walking = new Walk();
	Idle = new Standing();

	commands[SDLK_1] = Climbing;
	commands[SDLK_2] = Jumping;
	commands[SDLK_3] = Walking;
	commands[SDLK_r] = Idle;
	//commands[SDLK_1] = Falling;

}

InputHandler::~InputHandler()
{
	// Delete all command pointers    
	std::map<int, Command*>::iterator iter;
	for (iter = commands.begin(); iter != commands.end(); iter++)
		delete iter->second;
}

bool InputHandler::generateInputs(std::vector<Command*>& command_queue)
{
	bool exit = inputToAction();    // converts raw input datum to an action and/or state

	if (exit)
	{
		return true;
	}
	else 
	{
		fillCommands(command_queue);  // fills command queue
		action_map.clear();         // clears key presses
		return false;
	}
}

void InputHandler::bindings(int key, Command* command)
{
	commands[key] = command; // key pressed is pointed to the command
}


bool InputHandler::inputToAction()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
		if (event.type == SDL_QUIT) // 
		{
			return true;
		}
		else if (event.type == SDL_KEYDOWN) 
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				return true;
			}
			keydown(event);
		}
		else if (event.type == SDL_KEYUP)
		{
			keyup(event);
		}

	return false;
}

void InputHandler::fillCommands(std::vector<Command*>& command_queue)
{
	std::map<int, Command*>::iterator iter; // creates the iterator for the commands list
	for (iter = commands.begin(); iter != commands.end(); iter++) 
	{
		if (is_held(iter->first) && iter->second->type() == STATE)
		{
			command_queue.push_back(iter->second); //adds to the queue
		}
		else if (was_pressed(iter->first) && iter->second->type() == ACTION)
		{
			command_queue.push_back(iter->second); // adds to the queue
		}
	}
}

void InputHandler::keydown(SDL_Event& event)
{
	if (state_map[event.key.keysym.sym] == RELEASED)
	{
		action_map[event.key.keysym.sym] = EXECUTE;
		state_map[event.key.keysym.sym] = PRESSED;
	}
}

void InputHandler::keyup(SDL_Event& event)
{
	state_map[event.key.keysym.sym] = RELEASED; // if the key has been released


}

bool InputHandler::is_held(int key)
{
	return state_map[key]; // returns the current button pressed
}

bool InputHandler::was_pressed(int key)
{
	return action_map[key]; 
}
