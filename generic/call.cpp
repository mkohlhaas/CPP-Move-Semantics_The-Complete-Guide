#include "call.hpp"
#include <iostream>
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
    std::cout << "s:   " << s << '\n';
    std::cout << "ref: " << ref << '\n';

    auto str = std::move(ref);                  // move value from s and ref to str
    std::cout << "s: " << s << '\n';
    std::cout << "ref: " << ref << '\n';
    std::cout << "str: " << str << '\n';

    call(print, std::cout, str) << '\n'; // call() returns reference to std::cout
}
