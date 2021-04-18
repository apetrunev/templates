#include <iostream>
#include <string>

extern "C" {
int function(int (*fp)(int), int size)
{
	return (*fp)(size);
}
};

class cObject {
public:
	int operator()(int v) const
	{
		std::cout << v << std::endl;
		return 0;
	}
};

int main(int argc, char *argv[])
{
	cObject callObject;
	
	callObject(50);
	function([](int v) -> int { std::cout << v << std::endl; return 0; }, 5);
	return 0;
}
