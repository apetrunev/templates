#include <iostream>
#include <functional>
#include <string>
#include <type_traits>

#if 0
template<typename T>
T retV(T p) // T might become a reference
{
	return T{}; // return a reference if T is a reference
}
#endif 
// use type trait to convert to nonreference
template<typename T>
typename std::remove_reference<T>::type retV(T p)
{
	return p;
}

#if 0
// auto always decay
template<typename T>
auto retV(T p) // by value return type deduced by compiler
{
	return T{}; // always returns by value
}
#endif

int main(int argc, char *argv[])
{
	int x;
	retV<int&>(x);
	return 0;
}
