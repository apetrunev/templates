#ifndef STACK_STRING_H_
#define STACK_STRING_H_

#include "Stack.h"

#include <deque>
#include <string>
#include <cassert>

// specialization of Stack template for std::string
template<>
class Stack<std::string> {
private:
	std::deque<std::string> elems;
public:
	void push(std::string const&);	// push element
	void pop();			// pop element
	std::string const& top() const;	// return top element
	bool empty() const {		// return whether the stack is empty
		return elems.empty();
	}
};

// reference semantic to pass argument
void Stack<std::string>::push(std::string const& elem)
{
	elems.push_back(elem); // append copy of passed element
}

void Stack<std::string>::pop()
{
	assert(!elems.empty());
	elems.pop_back();	// remove last element
}

std::string const& Stack<std::string>::top() const
{
	assert(!elems.empty());
	return elems.back();	// return copy of last element
}

#endif // STACK_STRING_H_
