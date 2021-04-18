#include <iostream>

#if 0
// argument deduction does not work for default call argument
template<typename T>
void f(T t = "")
{
	std::cout << "Result " << t << std::endl; 
}
#endif

// to support this we need do declare default argument for template parameter
template<typename T = std::string>
void f(T t = "here goes an empty string")
{
	std::cout << "Result " << t << std::endl;
}

int main(int argc, char *argv[])
{
	f(1);
	f();
	return 0;
}
