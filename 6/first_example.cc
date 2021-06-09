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

// let f() forward argument val to g()
void f(X& val)
{
	g(val); // val is non-const lvalue => calls g(X&)
}

void f(X const& val)
{
	g(val); // val is const lvalue => class g(X const&)
}
// according to language rules move sematic is not passed through
void f(X&& val)
{
	g(std::move(val)); // val is non-const lvalue => needs std::move() to call g(X&&)
}

int main(int argc, char *argv[])
{
	X v;
	X const c;

	f(v); // f() for nonconstant object calls f(X&) => calls g(X&)
	f(c); // f() for constant object calls f(X const&) => calls g(X const&)
	f(X()); // f() for temporary calls f(X&&) => calls g(X&&)
	f(std::move(v)); // f() for movable variable calls f(X&&) => calls g(X&&)
	return 0;
}
