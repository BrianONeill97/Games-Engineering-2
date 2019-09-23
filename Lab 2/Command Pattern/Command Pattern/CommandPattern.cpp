#include <iostream>
#include <list>
#include <windows.h>
#include<iterator>

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;

protected:
	Command() {};
};

class Que : public Command
{
public:
	virtual void execute() { std::cout << "Q"; }
};

class UU : public Command
{
public:
	virtual void execute() { std::cout << "W"; }
};

class E : public Command
{
public:
	virtual void execute() { std::cout << "E"; }
};

class arrrrr : public Command
{
public:
	virtual void execute() { std::cout << "R"; }
};

class tee : public Command
{
public:
	virtual void execute() { std::cout << "T"; }
};

class why : public Command
{
public:
	virtual void execute() { std::cout << "T"; }
};

class InputHandler
{
public:
	void handleInput() {
		if (GetKeyState(VK_SHIFT) & 0x8000)
		{
			buttonQ_->execute();
		}
	};

private:
	Command* buttonQ_;
	Command* buttonW_;
	Command* buttonE_;
	Command* buttonR_;
	Command* buttonT_;
	Command* buttonY_;

};

//class MacroCommand : public Command {
//public:
//	MacroCommand();
//	virtual ~MacroCommand();
//	virtual void add(Command*);
//	virtual void remove(Command*);
//	virtual void execute();
//
//private:
//	std::list <Command*>* commands;
//
//};
//
//
//void MacroCommand::execute()
//{
//
//}

int main()
{
	InputHandler input;
	input.handleInput();
	system("pause");
}
