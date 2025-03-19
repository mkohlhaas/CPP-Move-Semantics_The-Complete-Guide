#include <utility>

class X
{
};

// Uncomment lines to see which functions are called!
void foo(const X &);  // for constant values (read-only access)
void foo(const X &&); // for constant rvalues (mostly doesn't make sense; only for demonstration purposes)
void foo(X &);        // for variable values (out parameters)
void foo(X &&);       // for values that are no longer used (move semantics)

// To avoid overloading functions for parameters with different value categories, C++ introduced a special
// mechanism for perfect forwarding. You need three things:
//
// 1. Take the call parameter as a pure rvalue reference (declared with && but without const or volatile), called
//    universal reference/forwarding reference:
//    They can universally bind to objects of all types (const and non-const) and value categories.
// 2. The type of the parameter has to be a template parameter of the function.
// 3. When forwarding the parameter to another function, use a helper function called std::forward<>(), declared in
//    <utility>.
template <typename T>
void
callFoo(T &&arg)               // universal reference (preserves the constness and value category!)
{
    foo(std::forward<T>(arg)); // Just like for std::move(), the semantic meaning of std::forward<>() is I no longer
                               // need this value here. So again, all you should assume is that after using
                               // std::forward<>(), the object is usually valid but you do not know its value.
}

// Note that a generic rvalue reference that is qualified with const (or volatile) is NOT a universal reference.
template <typename T>
void callFoo(const T &&arg); // arg is an rvalue

int
main(int argc, char *argv[])
{
    X       x;
    X const xc;

    foo(x);
    foo(xc);
    foo(X{});
    foo(std::move(x));
    foo(std::move(xc));

    callFoo(x);
    callFoo(xc);
    callFoo(X{});
    callFoo(std::move(x));
    callFoo(std::move(xc));
}
