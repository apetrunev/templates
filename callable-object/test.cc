#include<type_traits>
#include<utility>
#include<iostream>

template<typename Callable>
union storage
{
    storage() {}
    std::decay_t<Callable> callable;
};

template<int, typename Callable, typename Ret, typename... Args>
auto fnptr_(Callable&& c, Ret (*)(Args...))
{
    static bool used = false;
    static storage<Callable> s;
    using type = decltype(s.callable);

    if(used)
        s.callable.~type();
    new (&s.callable) type(std::forward<Callable>(c));
    used = true;

    return [](Args... args) -> Ret {
        return Ret(s.callable(std::forward<Args>(args)...));
    };
}

template<typename Fn, int N = 0, typename Callable>
Fn* fnptr(Callable&& c)
{
    return fnptr_<N>(std::forward<Callable>(c), (Fn*)nullptr);
}
void foo(void (*fn)())
{
    fn();   
}

int main()
{
    int i = 42;
    auto fn = fnptr<void()>([i]{std::cout << i;});
    foo(fn);  // compiles!
}
