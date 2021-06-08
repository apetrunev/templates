#include <iostream>
#include <string>

class BoolString {
private:
	std::string value;
public:
	BoolString(std::string const& s): value(s) {}
	template<typename T = std::string>
	T get() const // get value (converted to T)
	{
		return value;
	}
};

// full specialiazation for BoolString::getValue<>() for bool
template<>
inline bool BoolString::get<bool>() const
{
	return value == "true" || value == "1" || value == "on";
}

int main(int argc, char *argv[])
{
	BoolString s1("hello");
	std::cout << s1.get() << std::endl;
	std::cout << s1.get<bool>() << std::endl;
	return 0;
}
