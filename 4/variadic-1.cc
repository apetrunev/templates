#include <iostream>

// to ed recursion nontemplate overload of print is provided
// called when paramter pack is empty
void print()
{

}

// if one or more arguments are passed template function is called
template<typename T, typename...Types>
void print(T firstArg, Types... args)
{
	// print first argument
	std::cout << firstArg << std::endl;
	// recursively call print
	printf(args...);
}

int main(int argc, char *argv[])
{
	
	return 0;
}
