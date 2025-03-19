#include "call.hpp"
#include <iostream>
#include <print>
#include <string>

std::string
nextString()
{
    return "Let's dance";
}

std::ostream &
print(std::ostream &strm, const std::string &val)
{
    return strm << "value: " << val;
}

std::string &&
returnArg(std::string &&arg)
{
    return std::move(arg);
}

int
main()
{
    auto s = call(nextString);                  // call() returns temporary object

    auto &&ref = call(returnArg, std::move(s)); // call() returns rvalue reference to s
    std::println("s:   ", s);                   // s:
    std::println("ref: ", ref);                 // ref:

    auto str = std::move(ref);                  // move value from s and ref to str
    std::println("s: ", s);                     // s:
    std::println("ref: ", ref);                 // ref:
    std::println("str: ", str);                 // str:

    call(print, std::cout, str) << '\n';        // value: Let's dance (call() returns reference to std::cout)
}
