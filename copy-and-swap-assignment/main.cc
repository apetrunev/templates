#include <iostream>
#include <string>

class Obj;
static void print(const Obj &obj);

class Obj {
friend void print(const Obj &obj);
public:
	Obj() = default;
	Obj(int v): val(v) {}
	Obj(Obj &rhs) = default;
	Obj(Obj &&rhs) noexcept: val(rhs.val) { rhs.val = 0; }
	// assignment has nonreference type
	// parameter is copy initialized
	// depending on the type of the argument copy initialization uses
	// either the copy constructor or move constructor
	// lvalues are copied, rvalues are moved
	Obj& operator=(Obj rhs)
	{
		swap(*this, rhs);
		return *this;	
	}
	~Obj() {}
private:
	void swap(Obj &lhs, Obj &rhs)
	{
		int tmp;
		tmp = lhs.val;
		lhs.val = rhs.val;
		rhs.val = tmp;
	}
private:
	int val;
};

static void print(const Obj &obj)
{
	std::cout<< "Object value " << obj.val << std::endl;
}

int main(int argc, char *argv[])
{
	Obj o1(1), o2(2);

	::print(o1);
	::print(o2);
	o1 = o2;
	::print(o1);
	::print(o2);
	o1 = std::move(o2);
	::print(o1);
	::print(o2);	
	return 0;
}
