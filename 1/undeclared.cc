#include <iostream>

// 
template<typename T>
void foo(T t)
{
	undeclared(); // first time compile error if undeclared() is unknown
	undeclared(t); // second time compile error if undeclared is unknown
	static_assert(sizeof(int) > 10, "int too small"); // always fails if sizeof(int) <= 10
	static_assert(sizeof(t) > 10, "T too small"); // fails it instantiated for T with size <= 10
}

int main(int argc, char *argv[])
{
	foo(1);
	return 0;
}
