#include <iostream>

// overloading variadic and nonvariadic templates
template<typename T>
void print(T arg)
{
	std::cout << arg << std::endl;
}

// if two function only differ by a trailing paramter pack the
// function templte without the trailing parameter pack is preferred.
template<typename T, typename... Types>
void print(T firstArg, Types...args)
{
	print(firstArg); // call print for the first argument
	print(args...);   // call print for meaning arguments
}

int main(int argc, char *argv[])
{
	print("7.2", "Hello, world", 1);
	return 0;
}
