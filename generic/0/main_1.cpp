#include <utility>

class X
{
};

// For perfect forwarding in generic code, we would always need all these overloads for each parameter.
// To support all combinations, this means having 16 overloads for 2 generic arguments and 64 overloads for 3
// generic arguments.
//
// Therefore, C++11 introduced a special way to perfectly forward given arguments without any overloads
// but still keeping the type and the value category.

// Uncomment lines to see which functions are called!
void foo(const X &);  // for constant values (read-only access)
void foo(const X &&); // for constant rvalues (mostly doesn't make sense; only for demonstration purposes)
void foo(X &);        // for variable values (out parameters)
void foo(X &&);       // for values that are no longer used (move semantics)

void
callFoo(const X &arg)
{
    foo(arg);
    foo(std::move(arg));
}

void
callFoo(const X &&arg)
{
    foo(arg);
    foo(std::move(arg));
}

void
callFoo(X &arg)
{
    foo(arg);
    foo(std::move(arg));
}

void
callFoo(X &&arg)
{
    foo(arg);
    foo(std::move(arg));
}

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
