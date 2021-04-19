#include <iostream>

#if __cplusplus	== 201402L
// c++14
// return type is deduced from return statements
// return statements have to match and code be available
template<typename T1, typename T2>
auto max(T1 a, T2 b)
{
	return b < a ? a : b;
}
#elif __cplusplus == 201103L

// c++11
// trailing return type allow use call paramters
// declare that return type is derived from operator ?: yields
template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b < a ? a : b)
{
	return b < a ? a : b;
}
#endif
int main(int argc, char *argv[])
{
	auto ret = ::max(1, 2);
	std::cout << ret << std::endl;
	return 0;
}
