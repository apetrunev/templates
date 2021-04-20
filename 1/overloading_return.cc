#include <iostream>

template<typename T1, typename T2>
auto max(T1 a, T2 b)
{
	return b < a ? a : b;
}

template<typename RT, typename T1, typename T2>
RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}

int main(int argc, char *argv[])
{
	auto v1 = ::max(4, 7.2);
	auto v2 = ::max<long double>(7.2, 4);
	// conflict, both template match
	auto v3 = ::max<int>(4, 7.2);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;	
	return 0;
}
