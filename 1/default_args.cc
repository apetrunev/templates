#include <iostream>
#include <string>
#include <type_traits>

#if 0 
// ensure that no reference can be returned
// this implementation requires default constructors for the passed types
template<typename T1, typename T2,
	 typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}
#endif

// std::common_type_t decays so that the return value cannot become a reference
template<typename T1, typename T2,
	 typename RT = std::common_type_t<T1, T2>>
RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}

int main(int argc, char *argv[])
{
	::max(1, 2);
	return 0;
}
