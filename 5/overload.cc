#include <iostream>

template<typename T>
struct MyClass {}; // primary template

// partial specialization for arrays
template<typename T, std::size_t SZ>
struct MyClass<T[SZ]>
{
	static void print() { std::cout << "print() for T[" << SZ << "]" << std::endl; }
};
// partial specialization for references to arrays of known bounds
template<typename T, std::size_t SZ>
struct MyClass<T (&)[SZ]>
{
	static void print() { std::cout << "print() for T(&)[" << SZ << "]" << std::endl; }
};
// partial specialization for arrays of unknown bounds
template<typename T>
struct MyClass<T[]>
{
	static void print() { std::cout << "print() for T[]" << std::endl; }
};
// partial specialization for arrays of unknown bounds
template<typename T>
struct MyClass<T(&)[]>
{
	static void print() { std::cout << "print() for T(&)[]" << std::endl; }
};
// partial specialization for pointers
template<typename T>
struct MyClass<T*>
{
	static void print() { std::cout << "print() for T*" << std::endl; }
};

template<typename T1, typename T2, typename T3>
void foo(int a1[7], int a2[], int (&a3)[42], int (&x0)[], T1 x1, T2 &x2, T3 &&x3)
{
	MyClass<decltype(a1)>::print(); // uses MyClass<T*>
	MyClass<decltype(a2)>::print(); // uses MyClass<T*>
	MyClass<decltype(a3)>::print(); // uses MyClass<T (&)[SZ]>
	MyClass<decltype(x0)>::print(); // uses MyClass<T (&)[]>
	MyClass<decltype(x1)>::print(); // uses MyClass<T*>
	MyClass<decltype(x2)>::print(); // uses MyClass<T (&)[]>
	MyClass<decltype(x3)>::print(); // uses MyClass<T (&)[]>
}

int x[] = {0, 8, 15};

int main(int argc, char *argv[])
{
	int a[42];

	MyClass<decltype(a)>::print(); // uses MyClass<T[SZ]>

	extern int x[]; // forward declare array
	MyClass<decltype(x)>::print(); // uses MyClass<T[]>

	foo(a, a, a, x, x, x, x);	
	return 0;
}
