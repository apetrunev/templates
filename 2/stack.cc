#include <vector>
#include <cassert>
#include <iostream>

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


int main(int argc, char *argv[])
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	std::cout << "Top: " << s.top() << std::endl;
	s.pop();
	std::cout << "Top: " << s.top() << std::endl;
	s.pop();
	if (s.empty()) std::cout << "Stack is empty" << std::endl;
	return 0;
}
