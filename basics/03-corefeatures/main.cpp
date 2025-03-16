#include <print>
#include <utility>
#include <vector>

// takes the object by value
void
fooByVal(std::string str)
{
    std::println("{}", __PRETTY_FUNCTION__);
    std::println("{}", str);
};

// takes the object by rvalue reference
void
fooByRRef(std::string &&str)
{
    std::println("{}", __PRETTY_FUNCTION__);
    std::println("{}", str);
};

std::string
returnStringByValue()
{
    std::string ret{"foo"};
    return ret;
};

void
// foo(std::string &)
foo(const std::string &)
{
    std::println("{}", __PRETTY_FUNCTION__);
};

int
main()
{
    std::println("====================== 1 =================================");

    // vector of ints
    std::vector<int> coll;
    int              x{42};
    coll.push_back(std::move(x));
    std::println("{}", x);

    std::println("====================== 2 =================================");

    // vector of strings
    std::vector<std::string> coll_str;
    std::string              s{"just a string"};
    // const std::string        s{"just a string"};
    coll_str.push_back(s);
    coll_str.push_back(std::move(s));
    std::println("{}", s);

    std::println("====================== 3 =================================");

    std::string s1{"hello"};
    // std::string &&r1{s1};                 // ERROR
    std::string &&r2{std::move(s1)};         // OK
    std::string &&r3{returnStringByValue()}; // OK, extends lifetime of return value
    auto        &&r4{returnStringByValue()}; // OK, extends lifetime of return value

    std::println("{}", r2);
    std::println("{}", r3);
    std::println("{}", r4);

    std::println("====================== 4 =================================");

    // const std::string s2{"hello"}; //
    std::string s2{"hello"}; //
    foo(s2);                 // calls foo(), s2 keeps its value
    std::println("{}", s2);
    foo(std::move(s2));      // also calls foo(), s2 keeps its value
    std::println("{}", s2);

    std::println("====================== 5 =================================");

    // - A function declared to take an argument by value will use move semantics.
    // - A function declared to support move semantics might not use move semantics.

    // Note again that the effect of move semantics does not guarantee that any
    // optimization happens at all or what the effect of any optimization is.
    //
    // All we know is that the passed object is subsequently in a valid but unspecified
    // state.

    std::string s3{"hello"}, s4{"hello"};
    fooByVal(std::move(s3));    // s3 is moved
    fooByRRef(std::move(s4));   // s4 might be moved (with this compiler it won't!)
    std::println("s3: {}", s3); // s3:
    std::println("s4: {}", s4); // s4: hello
}
