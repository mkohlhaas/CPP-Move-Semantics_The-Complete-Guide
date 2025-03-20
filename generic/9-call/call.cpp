#include "call.hpp"
#include <iostream>
#include <print>
#include <string>

// return by value
std::string
nextString()
{
    return "Let's dance";
}

// return by lvalue reference
std::ostream &
print(std::ostream &strm, const std::string &val)
{
    return strm << "value: " << val;
}

// return by rvalue reference
std::string &&
returnArg(std::string &&arg)
{
    return std::move(arg);
}

// perfect returning for all three functions

int
main()
{
    auto   s   = call(nextString);              // call() returns temporary object
    auto &&ref = call(returnArg, std::move(s)); // call() returns rvalue reference to s
                                                // but no move; ref is just an alias for s

    std::cout << "s:   " << s << '\n';          // s:   Let's dance
    std::cout << "ref: " << ref << '\n';        // ref: Let's dance

    std::println();

    auto str = std::move(ref);                  // move value from s and ref to str
    std::cout << "s: " << s << '\n';            // s:
    std::cout << "ref: " << ref << '\n';        // ref:
    std::cout << "str: " << str << '\n';        // str: Let's dance

    std::println();

    call(print, std::cout, str) << '\n';        // value: Let's dance
                                                // call() returns reference to std::cout
}
