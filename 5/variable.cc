#include <iostream>
#include <array>

template<typename T>
constexpr T pi{ 3.1415926535897932385 };

// array with N elements zero-initialized
template<int N>
std::array<int, N> arr{};

// type of dval depends on passed value
template<auto N>
constexpr decltype(N) dval = N;

template<typename T>
class MyClass {
public:
	static constexpr int max = 1000;
};
// different values for different specializations
template<typename T>
int myMax = MyClass<T>::max;

int main(int argc, char *argv[])
{
	std::cout << pi<double> << std::endl;
	std::cout << pi<float> << std::endl;
	
	std::cout << dval<'c'> << std::endl;
	// set first value of the array
	arr<10>[0] = 42;
	for (std::size_t i = 0; i < arr<10>.size(); ++i) {
		std::cout << arr<10>[i] << std::endl;	
	}

	std::cout << myMax<int> << std::endl;

	return 0;
}
