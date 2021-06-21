#include <iostream>


// avoid any unnecessary copying
template<typename T>
void printR(T const& arg)
{
	std::cout << arg << std::endl;
}

// allow passing const values
// that trigger an error in attempt to modify the value
template<typename T>
void outR(T&  arg)
{
	if (std::is_array<T>::value) {
		std::cout << "got array of " << std::extent<T>::value << "elems" << std::endl;
	}
}

#if 0
// disable passing const object
template<typename T>
void outR(T&  arg)
{
	static_assert(!std::is_const<T>::value, "out parameter of outR<T>(T&) is const");
	if (std::is_array<T>::value) {
		std::cout << "got array of " << std::extent<T>::value << "elems" << std::endl;
	}
}
#endif

template<typename T, typename = std::enable_if_t<!std::is_const<T>::value>>
void outR(T& arg)
{
	std::cout << "this function allow only non-const values" << std::endl;	
}
// when passing by reference no copy gets created
template<typename T>
void passR(T&& arg)
{
	std::cout << "Argument is passed by forwarding reference" << std::endl;
}

int main(int argc, char *argv[])
{
	std::string s = "hi";
	std::string const c = "hi";
	int arr[4];
		
	passR(s);
	passR(c); // T deduced as std::string const&
	passR("hi"); // T deduced as char const (&) [3]
	passR(arr); // T deduced as int (&) [4]
	return 0;
}
