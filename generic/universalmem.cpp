#include <iostream>
#include <string>
#include <vector>

template <typename T>
void
insert(T &coll, typename T::value_type &&arg)
{
    coll.push_back(arg);
}

int
main()
{
    std::vector<std::string> coll;
    //...
    insert(coll, std::string{"prvalue"}); // OK
    //...
    std::string str{"lvalue"};
    insert(coll, str);            // ERROR: T::value_type&& is not a universal reference
    insert(coll, std::move(str)); // OK
                                  //...
}
