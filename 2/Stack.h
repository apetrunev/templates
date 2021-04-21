#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <cassert>
#include <iostream>

// forward declare class to implement friend function later
template<typename T>
class Stack;
// define output operator for class to be a template
template<typename T>
std::ostream& operator<<(std::ostream& strm, Stack<T> const& s);

template<typename T>
class Stack {
// declare specialization of nonmember function template as a friend
friend std::ostream& operator<< <T> (std::ostream& strm, Stack<T> const &s);
private:
	std::vector<T> elems;
public:
	void push(T const& elem); // push element
	void pop();		  // pop element
	T const& top() const;	  // return top element
	bool empty() const {	  // return whether the stack is empty
		return elems.empty();	
	}
	void printOn(std::ostream& strm) const {
		for (T const& elem : elems) {
			strm << elem << " ";
		}
	}	
};

template<typename T>
std::ostream& operator<<(std::ostream& strm, Stack<T> const& s)
{
	s.printOn(strm);
	return strm;
}

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
