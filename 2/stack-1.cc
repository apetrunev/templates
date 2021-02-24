#include "stack.h"

// partial specializaton of class Stack<> for pointers
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
	elems.push_back(elem);
}

template<typename T>
T* Stack<T*>::pop()
{
	assert(!elems.empty());
	T *p = elems.back();
	elems.pop_back(); // remove last element
	return p; // return it (unlike in the general case)
}

template<typename T>
T* Stack<T*>::top() const
{
	assert(!elems.empty());
	return elems.back();
}

int main(int argc, char *argv[])
{
	return 0;
}
