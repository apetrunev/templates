#ifndef MYCLASS_H_
#define MYCLASS_H_

// specialize the relationship between multiple template paramters
template<typename T1, typename T2>
class MyClass {};
// partial specialization: both templates have the same type
template<typename T>
class MyClass<T, T> {};
// partial specialization: second type is int
template<typename T>
class MyClass<T, int> {};
// partial specialization: both template parameters are pointer types
template<typename T1, typename T2>
class MyClass<T1*,T2*> {};

#endif // MYCLASS_H_
