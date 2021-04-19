#include <iostream>
#include <type_traits>

#if __cplusplus == 201103L
template<typename T1, typename T2>
typename std::common_type_t<T1,T2>::type max(T1 a, T2 b)
{
	return b < a ? a : b;
}

#else
template<typename T1, typename T2>
std::common_type_t<T1,T2> max(T1 a, T2 b)
{
	return b < a ? a : b;
}
#endif

int main(int argc, char *argv[])
{
	::max(1, 2);
	return 0;
}
