#include <iostream>

template<typename T>
void foo(T p = T{}) // OK (must use T() before C++11)
{
	// T x; // x has undefined value if T is built-in type
	T x{}; // value initialization, x is value initialized even for built-in types
}

template<typename T>
class MyClass {
private:
	//T x;
	T x{}; // since c++11: zero-initialize unless otherwise specified
public:
	MyClass(): x{} {} // since c++11: ensures that x is initialized even for built-in type	
	// MyClass(): x() {} // prior c++11
};

int main(int argc, char *argv[])
{
	foo<int>();
	return 0;
}
