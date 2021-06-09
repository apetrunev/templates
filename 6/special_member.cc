#include <utility>
#include <string>
#include <iostream>

template<typename T>
std::enable_if_t<(sizeof(T) > 4)>
foo() {}

template<typename T>
std::enable_if_t<(sizeof(T) > 4), T>
foo1() {}

template<typename T, typename = std::enable_if_t<(sizeof(T) > 4)>>
void foo2() {}

template<typename T>
using EnableIfSizeGreater4 = std::enable_if_t<(sizeof(T) > 4)>;

template<typename T, typename = EnableIfSizeGreater4<T>>
void foo3() {}


template<typename T>
using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;

class Person {
private:
	std::string name;
public:
	explicit Person(std::string const& n): name(n)
	{
		std::cout << "copying string-COSTR for '" << name << "'" << std::endl;
	}
	template<typename STR, typename = EnableIfString<STR>>
	explicit Person(STR&& n) : name(std::forward<STR>(n))
	{
		std::cout << "moving string-CONSTR for '" << name << "'" << std::endl;
	}

	// copy and move constructor
	Person(Person const& p) : name(p.name)
	{
		std::cout << "COPY-CONSTR Person '" << name << "'" << std::endl;
	}

	Person(Person&& p) : name(std::move(p.name))
	{
		std::cout << "MOVE-CONSTR Person '" << name << "'" << std::endl;
	}
};

class C {
public:
	C() = default;
	// user-define the predefined copy constructor as deleted
	// (with conversion to volatile to enable better matches)
	// doing so prevent another copy constructor to implicitly declared
	C(C const volatile&) = delete;
#if 0
	template<typename T>
	C (T const&)
	{
		std::cout << "Template copy constructor" << std::endl;
	}
#endif
	// if T is no integral type, provide copy constructor template
	// with better match
	template<typename U, typename = std::enable_if_t<!std::is_integral<U>::value>>
	C (U const&)
	{
		std::cout << "Better match for non-integral type" << std::endl;
	}
};

int main(int argc, char *argv[])
{
	std::string s = "sname";
	Person p1(s); // init with string object => calls copying string-CONSTR
	Person p2("tmp"); // init with string literal => calls moving string-CONSTR
	Person p3(p1); // copy Person => calls COPY-CONSTR
	Person p4(std::move(p1)); // move Person => calls MOVE-CONST
	
	C x;
	C y{x}; // still uses predefined copy constructor (not the member template)

	return 0;
}
