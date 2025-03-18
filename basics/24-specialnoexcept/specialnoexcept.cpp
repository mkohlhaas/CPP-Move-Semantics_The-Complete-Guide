#include <print>
#include <type_traits>

// By rule, a noexcept condition is generated when special member functions are generated but not imple-
// mented.3 In that case, the operations guarantee not to throw if the corresponding operations called for all
// bases classes and non-static members guarantee not to throw.
class B
{
    std::string s;
};

// Note: the noexcept condition is even generated when these special member functions are user-declared
// with =default.
class C
{
    std::string s;

  public:
    C(const C &)            = default; // noexcept condition automatically generated
    C(C &&)                 = default; // noexcept condition automatically generated
    C &operator=(const C &) = default; // noexcept condition automatically generated
    C &operator=(C &&)      = default; // noexcept condition automatically generated
};

// When you have a defaulted special member function you can explicitly specify a different
// noexcept guarantee than the generated one.
class D
{
  public:
    D(const D &) noexcept   = default; // guarantees not to throw       (OK since C++20)
    D(D &&) noexcept(false) = default; // specifies that it might throw (OK since C++20)

    // ...
};

int
main()
{
    // The generated copy constructor and copy assignment operator might throw because copying a std::string
    // might throw. However, the generated default constructor, move constructor, and move assignment operator
    // guarantee not to throw because the default constructor, move constructor, and move assignment operator of
    // class std::string guarantee not to throw.

    std::println("{}", std::is_nothrow_default_constructible<B>::value); // true
    std::println("{}", std::is_nothrow_copy_assignable<B>::value);       // false
    std::println("{}", std::is_nothrow_copy_constructible<B>::value);    // false
    std::println("{}", std::is_nothrow_move_constructible<B>::value);    // true
    std::println("{}", std::is_nothrow_move_assignable<B>::value);       // true
}
