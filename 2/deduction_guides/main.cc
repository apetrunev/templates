#include "../Stack.h"

#include <iostream>
#include <string>

// arggregate type
template<typename T>
struct ValueWithComment {
	T value;
	std::string comment;
};

ValueWithComment(char const*, char const *) -> ValueWithComment<std::string>;

int main(int argc, char *argv[])
{
	Stack<int> intStack1;
	Stack<int> intStack2 = intStack1;
	Stack intStack3 = intStack1; // c++17
	
	Stack stringStack("string");
	// c++17
	// allow because deduction guides
	// no constructor to perform deductuion against
	ValueWithComment vs = { "hello", "initial value" };

	return 0;

}
