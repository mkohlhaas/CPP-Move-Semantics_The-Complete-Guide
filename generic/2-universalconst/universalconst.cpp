#include <print>
#include <string>

void
iterate(std::string::iterator beg [[maybe_unused]], std::string::iterator end [[maybe_unused]])
{
    std::println("do some non-const stuff with the passed range");
}

void
iterate(std::string::const_iterator beg [[maybe_unused]], std::string::const_iterator end [[maybe_unused]])
{
    std::println("do some     const stuff with the passed range");
}

template <typename T>
void
process(T &&coll)
{
    iterate(coll.begin(), coll.end());
}

int
main()
{
    std::string       v{"v"};
    const std::string c{"c"};

    process(v);                // do some non-const stuff with the passed range
    process(c);                // do some     const stuff with the passed range
    process(std::string{"t"}); // do some non-const stuff with the passed range
    process(std::move(v));     // do some non-const stuff with the passed range
    process(std::move(c));     // do some     const stuff with the passed range
}
