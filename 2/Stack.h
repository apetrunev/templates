#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <cassert>

template<typename T>
class Stack {
private:
	std::vector<T> elems;
public:
	void push(T const& elem); // push element
	void pop();		  // pop element
	T const& top() const;	  // return top element
	bool empty() const {	  // return whether the stack is empty
		return elems.empty();	
	}
};

#if 0
template<typename T>
class Stack {
private:
	std::vector<T> elems;
public:
	// use class name not followed by template arguments
	// in that case template paramters are used as arguments for a class 
	Stack(Stack const& rhs);
	Stack& operator=(Stack& rhs);
};
#endif

// member function is a template
// use full type qualification
template<typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);	// append copy of passed elem
}
template<typename T>
void Stack<T>::pop()
{
	assert(!elems.empty());
	elems.pop_back();	// remove last element
}

template<typename T>
T const& Stack<T>::top() const
{
	assert(!elems.empty());
	return elems.back(); // return copy of last element
}

#endif // STACK_H_ 
