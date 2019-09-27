#include "Command.h"

void MacroCommand::execute()
{
	std::list<Command*>::iterator i(commands);

	for (i.first; !i.isDone; i.Next())
	{

	}
}
