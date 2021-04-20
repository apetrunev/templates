#include <iostream>

// max of two values of any type
template<typename T>
T max(T a, T b)
{
	std::cout << "max<T> " << std::endl;
	return b < a ? a : b;
}

// max of thre values of any type
template<typename T>
T max(T a, T b, T c)
{
	// uses the template version even for ints
	// because the following declaration comes too late
	return max(max(a, b), c);
}

// max of two int values
int max(int a, int b)
{
	std::cout << "max(int, int)" << std::endl;
	return b < a ? a : b;
}

int main(int argc, char *argv[])
{
	::max(47, 11, 33);
	return 0;
}
