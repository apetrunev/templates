#include <iostream>

template<typename T, typename... Types>
void print(T firstArg, Types... args)
{
	// new form of sizeof for variadic templates
	// expand to the number of elements the parameter pack contains
	// can be user for template parameter pack and function paramter pack
	std::cout << sizeof...(Types) << std::endl;
	std::cout << sizeof...(args) << std::endl;
}

int main(int argc, char *argv[])
{
	print("71.3", "The sentence", 213);
	return 0;
}
