#include <iostream>
#include <string>

template<typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

int main(int argc, char *argv[])
{
	int i = 42;
	
	// :: in front of template means that our template is found in global namespace
	std::cout << ::max(7, i) << std::endl;

	std::string s1 = "mathematics";
	std::string s2 = "math";
	
	std::cout << ::max(s1, s2) << std::endl;

	return 0;
}
