#include <iostream>

// C++17 compute binary operation over all the arguments of a parameter pack

template<typename... T>
auto foldSum(T... s)
{
	return (... + s); // ((s1 + s2) + s3) ...
}

template<typename... Types>
void print(Types const&... args)
{
	(std::cout << ... << args) << std::endl;
}

int main(int argc, char *argv[])
{
	auto s = foldSum(1, 1, 1, 1, 1); // 5
	std::cout << s << std::endl;
	return 0;
}
