#include <iostream>
#include <string>
#include <type_traits>

// user std::decay_t to ensure to reference can be returned
// c++14
// requires to call default constructors
template<typename T1, typename T2, typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}

template<typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
RT _max(T1 a, T2 b)
{
	return b < a ? a : b;
}

int main(int argc, char *argv[])
{

	return 0;
}
