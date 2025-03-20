#include <print>
#include <string>

// - A universal reference is the only way we can bind a reference to objects of any value category and still preserve
//   whether or not it is const.
// - The only other reference that binds to all objects, const&, loses the information about whether the passed argument
//   is const or not.

using iterator       = std::string::iterator;
using const_iterator = std::string::const_iterator;

void
iterate(iterator beg [[maybe_unused]], iterator end [[maybe_unused]])
{
    std::println("do some non-const stuff with the passed range");
}

void
iterate(const_iterator beg [[maybe_unused]], const_iterator end [[maybe_unused]])
{
    std::println("do some     const stuff with the passed range");
}

// For a non-const object v and a const object c the type T and the type of arg is deduced as follows:
//
//              | T             | arg          | simplified value category of arguement to foo
// -------------------------------------------------------------------------------------------
// foo(v)       | Type&         | Type&        | lvalue
// foo(c)       | const Type&   | const Type&  | lvalue
// foo(Type{})  | Type          | Type&&       | rvalue
// foo(move(v)) | Type          | Type&&       | rvalue
// foo(move(c)) | const Type    | const Type&& | rvalue

template <typename T>
void
process(T &&coll) // universal reference keeps const information
{
    // NOTE: that we do not use (perfect) forwarding.
    // We just want to refer universally to both const and non-const objects.
    //
    // iterate(std::forward<T>(coll).begin(), std::forward<T>(coll).end()); // ???
    // You should never use std::move() or std::forward<>() twice for the same object
    // (unless the object was reinitialized before the second use).
    //
    // iterate(coll.begin(), std::forward<T>(coll).end()); // ???
    // We have no guaranteed evaluation order for arguments of function calls.

    // If you do not need the value category of the passed argument for perfect forwarding,
    // you do not need std::forward<>().

    iterate(coll.begin(), coll.end());
}

int
main()
{
    std::string       v{"v"};
    const std::string c{"c"};

    process(c);                // do some     const stuff with the passed range
    process(std::move(c));     // do some     const stuff with the passed range

    process(v);                // do some non-const stuff with the passed range
    process(std::string{"t"}); // do some non-const stuff with the passed range
    process(std::move(v));     // do some non-const stuff with the passed range
}
