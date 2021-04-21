#include "Stack.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	Stack<int> intStack;
	Stack<std::string> stringStack;

	intStack.push(7);
	std::cout << intStack.top() << std::endl;

	stringStack.push("hello");
	std::cout << stringStack.top() << std::endl;
	stringStack.pop();	
	return 0;
}
