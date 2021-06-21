#include <iostream>
#include <functional>
#include <string>

void printString(std::string const& s)
{
	std::cout << s << std::endl;
}

template<typename T>
void printT(T arg)
{
	printString(arg);
}

int main(int arg, char *argv[])
{	
	std::string s = "hello";
	printT(s);
	// pass s as if by reference
	// wraps the passed argument s by an object that acts like a reference
	// create an object of type std::reference_wrapper<> referring to the original argument ans passes this object by value
	// wrapper support conversion back to the original type
	printT(std::cref(s));

	return 0;
}
