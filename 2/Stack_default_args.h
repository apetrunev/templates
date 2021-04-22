#ifndef STACK_DEFAULT_ARGS_
#define STACK_DEFAULT_ARGS_

#include <vector>
#include <cassert>

// we have two template parameters 
// each definition of the functino must be defined with these two paramters
template<typename T, typename Cont = std::vector<T>>
class Stack {
private:
	Cont elems;
public:
	void push(T const& elem);	// push element
	void pop();			// pop element
	T const& top() const;		// return top element
	bool empty() const {		// return whether the stack is empty
		return elems.empty();
	}	
};

template<typename T, typename Cont>
void Stack<T,Cont>::push(T const& elem)
{
	elems.push_back(elem);		// append copy of passed elem
}

template<typename T, typename Cont>
void Stack<T, Cont>::pop()
{
	assert(!elems.empty());
	elems.pop_back();		// remove last element
}

template<typename T, typename Cont>
T const& Stack<T, Cont>::top() const
{
	assert(!elems.empty());
	return elems.back();		// return copy of last element
}

#endif // STACK_DEFAULT_ARGS_
