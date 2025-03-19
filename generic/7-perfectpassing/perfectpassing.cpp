#include <print>
#include <string>

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
    std::string str{"lvalue"};

    process(computeConstLRef("tmp"));     // process(const std::string&)
    process(computeLRef(str));            // process(std::string&)
    process(computeRRef("tmp"));          // process(std::string&&)
    process(computeRRef(std::move(str))); // process(std::string&&)
    process(computeValue("tmp"));         // process(std::string&&)
}
