#include <iostream>
#include <utility>

class X {};

void g(X&)
{
	std::cout << "g() for variable" << std::endl;
}

void g(X const&)
{
	std::cout << "g() for constant" << std::endl;
}

void g(X&&)
{
	std::cout << "g() for movable object" << std::endl;
}

template<typename T>
void f(T&& val)
{
	// forward potential move semantic depending on a passed template argument
	g(std::forward<T>(val));
}

int main(int argc, char *argv[])
{
	X v;
	X const c;

	f(v);
	f(c);
	f(X());
	f(std::move(v));
	return 0;
}
