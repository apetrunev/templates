#ifndef STACK_PARTIAL_H_
#define STACK_PARTIAL_H_

#include "Stack.h"

// partial specialization for pointers
// still parameterized for T but specialized for a pointer
// partial specialization provide slightly different interface
template<typename T>
class Stack<T*> {
private:
	std::vector<T*> elems;
public:
	void push(T*);
	T* pop();
	T* top() const;
	bool empty() const {
		return elems.empty();
	}

};

template<typename T>
void Stack<T*>::push(T *elem)
{
	elems.push_back(elem);	// append copy of the passed element
}

template<typename T>
T* Stack<T*>::pop()
{
	assert(!elems.empty());
	T* p = elems.back();
	elems.pop_back();	// remove last element
	return p;		// and return it (unlike in the general case)
}

template<typename T>
T* Stack<T*>::top() const
{
	assert(!elems.empty());
	return elems.back();	// return copy of last element
}

#endif // STACK_PARTIAL_H_

