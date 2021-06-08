#include <iostream>
#include <deque>

template<typename T, typename Cont = std::deque<T>>
class Stack {
private:
	Cont elems;
public:
	void push(T const&);
	void pop();
	T const& top() const;
	bool empty() const
	{
		return elems.empty();
	}
	template<typename T2, typename Cont2>
	Stack& operator=(Stack<T2,Cont2> const&);
	// get access to private members of Stack<T2> for any type T2
	template<typename, typename> friend class Stack;
};

template<typename T, typename Cont>
template<typename T2, typename Cont2>
Stack<T, Cont>& Stack<T, Cont>::operator=(Stack<T2, Cont2> const& op2)
{
	// remove existing elements
	elems.clear();
	// insert at the begining all elements from op2
	elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
	return *this;
}

int main(int argc, char *argv[])
{
	return 0;
}
