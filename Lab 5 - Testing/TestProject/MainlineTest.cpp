#include <iostream>
#include <assert.h>

#include "../ProductionProject/Production.h"


int main()
{
	Production p;

//	p.someMethod();
	assert(("True",p.someMethod() == true));
	std::cout << "Assertion Passed";
	assert(("Failed", p.someMethod() == false));
	std::cout << "Assertion Failed";

	std::cin.get();
	system("pause");
}