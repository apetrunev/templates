#include <iostream>
#include <deque>

template<typename T>
class Stack {
private:
	std::deque<T> elems;
public:
	void push(T const& elem)
	{
		elems.push_back(elem);
	}

	void pop() { elems.pop_front(); }
	
	T const& top() const
	{
		return elems.front();
	}

	bool empty() const
	{
		return elems.empty();
	}
	// making an assignment operator as a template can enable the assignment of stacks
	// with elements for which an appropriate type conversion is defined
	template<typename T2>
	Stack& operator=(Stack<T2> const &);
	// to get access to private members of Stack<T2> for any type T2
	// declare all other stack instances as friends
	// can omit template parameter name because it is not used
	template<typename> friend class Stack;
};

#if 0
template<typename T>
template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2)
{
	Stack<T2> tmp(op2); // copy of assigned stack
	elems.clear();
	while (!tmp.empty()) { // remove existing elements
		elems.push_front(tmp.top()); // copy all elements 
		tmp.pop();
	}
	return *this;
}
#endif

template<typename T>
template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2)
{
	elems.clear(); // remove existing elements
	// insert at the beginning all elements from op2
	// type checking is still working
	elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
	return *this;
}

int main(int argc, char *argv[])
{
	Stack<int> intStack;
	
	intStack.push(1);
	intStack.push(2);

	Stack<float> floatStack;

	floatStack.push(1.2);
	floatStack.push(4.3);

	intStack = floatStack;

	while (!intStack.empty()) {
		std::cout << intStack.top() << std::endl;
		intStack.pop();
	}
	return 0;
}
