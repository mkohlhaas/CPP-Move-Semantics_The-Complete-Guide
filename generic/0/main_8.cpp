#include <string>

// forward declarations:
std::string         retByValue();
std::string        &retByRef();
const std::string  &retByConstRef();
std::string       &&retByRefRef();
const std::string &&retByConstRefRef();

int
main()
{
    // deduced auto&& types:
    //
    // Same type deduction rules as universal references being function template parameters:
    //
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

    // auto&& is always a reference.

    std::string s;

    // argument (in {}) is an lvalue (value category): && ∀ & = &
    auto &&r1{s};               // std::string&
    auto &&r4{retByRef()};      // std::string&
    auto &&r6{retByConstRef()}; // const std::string&

    // argument (in {}) is an rvalue (value category): && ∀ && = &&
    auto &&r5{retByRefRef()};      // std::string&&
    auto &&r2{std::move(s)};       // std::string&&
    auto &&r3{retByValue()};       // std::string&&
    auto &&r7{retByConstRefRef()}; // const std::string&&

    // Because string literals are lvalues (with a character array as type) we also
    // get an lvalue reference when we bind the universal reference to a string literal:
    auto &&r8{"hello"}; // const char(&)[6] = lvalue reference

    // Because references to functions are always lvalues we also get an
    // lvalue reference when we bind the universal reference to a function:

    std::string foo(int); // forward declaration

    auto &&r9{foo};       // std::string(&)(int) = lvalue reference
}
