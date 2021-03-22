#include <iostream>
#include <string>

class Obj;
static void print(const Obj &obj);

class Obj {
friend void print(const Obj &obj);
public:
	Obj() = default;
	Obj(int v): val(v) {}
	Obj(const Obj &rhs) = default;
	Obj(Obj &&rhs) noexcept : val(rhs.val) { rhs.val = 0; }
	// executes only on lvalues
	Obj& operator=(const Obj &rhs) &
	{
		val = rhs.val;
		return *this;
	}
	Obj& operator+=(const Obj &rhs) {
		val += rhs.val;
		return *this;
	}
private:
	int val;	
};

static void print(const Obj &obj)
{
	std::cout << "Object value " << obj.val << std::endl;
}

Obj operator+(const Obj &lhs, const Obj &rhs) 
{
	Obj tmp = lhs;
	tmp += rhs;
	return tmp;	
}

int main(int argc, char *argv[])
{
	Obj o1(1), o2(2);
	Obj o3(3);
	
	::print(o2);
	::print(o2 + 5);
	return 0;
}
