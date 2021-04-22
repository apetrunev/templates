#include "Stack.h"
#include "Stack_string.h"
#include "Stack_partial.h"

#include "MyClass.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	Stack<int> intStack;
	Stack<std::string> stringStack;

	intStack.push(7);
	std::cout << intStack.top() << std::endl;

	std::cout << intStack << std::endl;
	stringStack.push("hello");
	std::cout << stringStack.top() << std::endl;
	stringStack.pop();	
	
	Stack<int*> ptrStack;
	ptrStack.push(new int{42});
	std::cout << *ptrStack.top() << std::endl;
	delete ptrStack.pop();
	
	MyClass<int, double> oid; // use MyClass<T1, T2>
	MyClass<int, float>  oif; // use MyClass<T, T>
	MyClass<float, int>  ofi; // use MyClass<T, int>
	MyClass<int*, float*> op; // use MyClass<T1*,T2*>

	return 0;
}
