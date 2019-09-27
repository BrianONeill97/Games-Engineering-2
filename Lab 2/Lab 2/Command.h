#pragma once
#include "SFML/Graphics.hpp"
#include <list>
#include <iostream>

using namespace std;
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
	virtual void execute() { std::cout << "Y"; }
};

class InputHandler
{
public:
	void handleInput() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			buttonQ_->execute();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			buttonW_->execute();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			buttonE_->execute();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			buttonR_->execute();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			buttonT_->execute();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			buttonY_->execute();
		}
	};

private:
	Command* buttonQ_ = new Que;
	Command* buttonW_ = new UU;
	Command* buttonE_ = new E;
	Command* buttonR_ = new arrrrr;
	Command* buttonT_ = new tee;
	Command* buttonY_ = new why;

};

class MacroCommand : public Command {
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();

private:
	std::list <Command*>* commands;

};

