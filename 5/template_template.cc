#include <iostream>
#include <deque>
// specify second template parameter as template
// template parameter of template template parameter is no used
template<typename T, template<typename> typename Cont = std::deque>
class Stack {
private:
	Cont<T> elems;
public:
	void push(T const&);
	void pop();
	T const& top() const;
	bool empty() const
	{
		return elems.empty();
	}
};

template<typename T, template<typename> class Cont>
void Stack<T, Cont>::push(T const& elem)
{
	elems.push_bach(elem);
}

int main(int argc, char *argv[])
{
		
	return 0;
}
