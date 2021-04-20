#include <iostream>
#include <cstring>

// max of two values of any type (call-by-reference)
template<typename T>
T const& max(T const& a, T const& b)
{
	return b < a ? a : b;
}
// max of two C-strings (call-by-value)
char const* max(char const *a, char const* b)
{
	return std::strcmp(b, a) < 0 ? a : b;
}
// max of three values of any type (call-by-reference)
template<typename T>
T const& max(T const& a, T const& b, T const& c)
{
	return max(max(a, b), c); // error if max(a, b) uses call-by-value
}

int main(int argc, char *argv[])
{
	auto m1 = ::max(7, 42, 68);
	char const* s1 = "frederic";
	char const* s2 = "anica";
	char const* s3 = "lucas";
	auto m2 = ::max(s1, s2, s3); // runtime error
	return 0;
}
