#ifndef STACK_H_
#define STACK_H_

#include <cassert>
#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
	std::vector<T> elems;
public:
	void push(T const& elem);
	void pop();
	T const& top() const;
	bool empty() const {
		return elems.empty();
	}
	// print stack content
	void printOn(std::ostream &strm) const {
		for (T const &elem : elems) {
			strm << elem << ' ';
		}
	}
	// templated entity
	// instantiated with the class template if needed
	friend std::ostream& operator<< (std::ostream& strm, Stack<T> const& s) {
		s.printOn(strm);
		return strm;
	}
};

template<typename T>
void Stack<T>::push(T const & elem)
{
	elems.push_back(elem); // append copy of passed elem
}

template<typename T>
void Stack<T>::pop()
{
	assert(!elems.empty());
	elems.pop_back(); // remove the last element
}

template<typename T>
T const& Stack<T>::top() const
{
	assert(!elems.empty());
	return elems.back(); // return copy of last element
}

#endif // STACK_H_
