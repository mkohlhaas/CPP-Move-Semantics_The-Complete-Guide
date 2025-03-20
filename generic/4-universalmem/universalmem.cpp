#include <string>
#include <vector>

// An rvalue reference to a member type of a template parameter is not a universal reference.

template <typename T>
void
insert(T &coll, typename T::value_type &&arg) // second argument is an rvalue, NOT a universal reference
{
    coll.push_back(arg);
}

int
main()
{
    std::vector<std::string> coll;

    insert(coll, std::string{"prvalue"}); // OK

    std::string str{"lvalue"};
    insert(coll, str);                    // ERROR: T::value_type&& is not a universal reference
    insert(coll, std::move(str));         // OK
}
