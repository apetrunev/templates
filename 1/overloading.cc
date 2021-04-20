#include <iostream>
#include <iomanip>

int max(int a, int b)
{
	return b < a ? a : b;
}

template<typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

int main(int argc, char *argv[])
{
	std::cout << ::max(7, 42) << std::endl; // calls nontemplate for ints
	std::cout << ::max(7.0, 42.0) << std::endl; // optimize and calls nontemplate
	std::cout << ::max(4.13, 5.234) << std::endl; // calls max<double> (by argument deduction)
	std::cout << ::max('a', 'b') << std::endl; // calls max<char> (by argument deduction)
	std::cout << ::max<>(7, 42) << std::endl; // calls max<int> (by argument deduction)
	std::cout << ::max<double>(7, 42) << std::endl; // calls max<double> (no argument deduction)
	std::cout << ::max('a', 42.7) << std::endl; // calls the nontemplate for two ints

	return 0;
}
