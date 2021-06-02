#include <iostream>

template<typename T>
class Base {
public:
	void bar();
};

void bar()
{
	std::cout << "This is external bar() function" << std::endl;
}

// for resolving the symbol bar() inside foo(), bar() defined in Base
// is never considered
// Always qualify any symbol that is declared in a base that is somehow dependent on a template
// parameter with this-> or Base<T>::
template<typename T>
class Derived: Base<T> {
public:
	void foo()
	{
		bar(); // calls external bar() or error
	}
};

int main(int argc, char *argv[])
{
	Derived<int> obj;
	obj.foo();
	return 0;
}
