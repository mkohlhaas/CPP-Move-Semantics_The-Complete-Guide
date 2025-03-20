#include <concepts>
#include <string>
#include <string_view>

// The fact that ordinary rvalue references and universal references share the same syntax creates multiple
// problems. It is not only that it is not easy to find out what we have; there is also the problem that you cannot
// declare a universal reference of a specific type.

// void processString(std::string&&& arg); // assume &&& declares a universal reference
// We do not have this specific syntax, however, and now we have existing code with both applications of &&.

// Since C++20, constraining a universal reference to specific types is possible with concepts and the keyword requires.

// require a universal reference of a specific type:
// - no implicit type conversions supported
template <typename T>
    requires std::same_as<std::remove_cvref_t<T>, std::string>
void
requireSame(T &&)
{
    //...
}

// require a universal reference of a specific type:
// - implicit but no explicit type conversions supported
template <typename T>
    requires std::convertible_to<T, std::string>
void
requireConvertible(T &&)
{
    //...
}

// different syntax
template <std::convertible_to<std::string> T>
void
requireConvertible_(T &&)
{
    //...
}

// require a universal reference of a specific type:
// - even explicit type conversions supported
// NOTE: the order of arguments differs (from convertible_to<>)
template <typename T>
    requires std::constructible_from<std::string, T>
void
requireConstructible(T &&)
{
    //...
}

// Does not work bc of order of arguments:
// template <std::constructible_from<std::string> T>
// void
// requireConstructible_(T &&)
// {
//     //...
// }

int
main()
{
    std::string      s  = "hi";
    std::string_view sv = "hi";

    requireSame(s);             // OK
    requireSame(sv);            // ERROR: no std::string
    requireSame("hi");          // ERROR: no std::string

    requireConvertible(s);      // OK
    requireConvertible(sv);     // ERROR: not implicit conversion to std::string
    requireConvertible("hi");   // OK

    requireConstructible(s);    // OK
    requireConstructible(sv);   // OK (explicit conversion used)
    requireConstructible("hi"); // OK
}
