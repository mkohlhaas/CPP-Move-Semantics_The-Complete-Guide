#include <print>
#include <string>

// Universal References with auto&&

void
process(const std::string &)
{
    std::println("process(const std::string&)");
}

void
process(std::string &)
{
    std::println("process(std::string&)");
}

void
process(std::string &&)
{
    std::println("process(std::string&&)");
}

const std::string &
computeConstLRef(const std::string &str)
{
    return str;
}

std::string &
computeLRef(std::string &str)
{
    return str;
}

std::string &&
computeRRef(std::string &&str)
{
    return std::move(str);
}

std::string
computeValue(const std::string &str)
{
    return str;
}

int
main()
{
    // r1 - r5 are universal references
    // Deduction according to the same type rules as universal references being function template parameters.

    auto &&r1 = computeConstLRef("tmp");     // WARNING: possibly dangling reference to a temporary
    process(std::forward<decltype(r1)>(r1)); // process(const std::string&)

    std::string str{"lvalue"};
    auto      &&r2 = computeLRef(str);
    process(std::forward<decltype(r2)>(r2)); // process(std::string&)

    auto &&r3 = computeRRef("tmp");          // WARNING: possibly dangling reference to a temporary
    process(std::forward<decltype(r3)>(r3)); // process(std::string&&)

    auto &&r4 = computeRRef(std::move(str));
    process(std::forward<decltype(r4)>(r4)); // process(std::string&&)

    auto &&r5{computeValue("tmp")};
    process(std::forward<decltype(r5)>(r5)); // process(std::string&&)
}
