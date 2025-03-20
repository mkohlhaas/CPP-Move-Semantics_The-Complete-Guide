#include <iostream>
#include <type_traits>

// Constness Dependent Code

// For a non-const object v and a const object c the type T and the type of arg is deduced as follows(!!!):
//
//              | T          | arg          | simplified value category of arguement to foo
// -------------------------------------------------------------------------------------------
// foo(v)       | T&         | T&           | lvalue [1]
// foo(c)       | const T&   | const T&     | lvalue [2]
// foo(T{})     | T          | T&&          | rvalue
// foo(move(v)) | T          | T&&          | rvalue
// foo(move(c)) | const T    | const T&&    | rvalue

// In [1] and [2] arg was defined as T&&. So what does that make arg?
// Using reference collapsing rules:
// T  | arg | resulting type for arg
// ------------------------------------------
// T& | &   | becomes T&
// T& | &&  | becomes T&  [it will become T&]
// T&&| &   | becomes T&
// T&&| &&  | becomes T&&

// if you only have to know whether the passed argument was const, you can use both arg and T
template <typename T>
void
foo1(T &&arg)
{
    // std::remove_reference_t<T> is a shortcut for std::remove_reference<T>::type
    // std::is_const_v<T>         is a shortcut for std::is_const<T>::value.

    if constexpr (std::is_const_v<std::remove_reference_t<T>>)
    {
        // passed argument is const
    }
    else
    {
        // passed argument is not const
    }
}

// Value Category Dependent Code

template <typename T>
void
foo2(T &&arg)
{
    if constexpr (std::is_lvalue_reference_v<T>)
    {
        // passed argument is lvalue (has no move semantics)
    }
    else
    {
        // passed argument is rvalue (has move semantics)
    }
}

int
main(int argc, char *argv[])
{
    // Note that it is important to use std::remove_reference<> to remove the
    // referenceness of T before we check for its constness.
    // A reference to a const type is not considered to be const as a whole [1]:

    std::cout << std::is_const_v<int> << std::endl;                                  // false
    std::cout << std::is_const_v<const int> << std::endl;                            // true
    std::cout << std::is_const_v<const int &> << std::endl;                          // false [1]
    std::cout << std::is_const_v<std::remove_reference_t<const int &>> << std::endl; // true
}
