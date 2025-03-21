#include <iostream>
#include <string>
#include <vector>

// primary template taking a universal reference:
template <typename Coll, typename T>
void
insert(Coll &coll, T &&arg)                                              // NOTE:universal reference
{
    std::cout << "primary template for universal reference of type T\n"; //
    coll.push_back(arg);
}

template <>
void
insert(std::vector<std::string> &coll, const std::string &arg)
{
    std::cout << "full specialization for type const std::string&\n";
    coll.push_back(arg);
}

template <>
void
insert(std::vector<std::string> &coll, std::string &arg)
{
    std::cout << "full specialization for type std::string&\n";
    coll.push_back(arg);
}

template <>
void
insert(
    std::vector<std::string> &coll,
    std::string &&arg) // NOTE:An rvalue reference to a parameter of a full specialization is NOT a universal reference.
{
    std::cout << "full specialization for type std::string&&\n";
    coll.push_back(arg);
}

template <>
void
insert(std::vector<std::string> &coll, const std::string &&arg)
{
    std::cout << "full specialization for type const std::string&&\n";
    coll.push_back(arg);
}

int
main()
{
    std::vector<std::string> coll;

    insert(coll, std::string{"prvalue"});   // full specialization for type std::string&&

    std::string str{"lvalue"};
    insert(coll, str);                      // full specialization for type std::string&
    insert(coll, std::move(str));           // full specialization for type std::string&&

    const std::string cstr{"const lvalue"}; //
    insert(coll, cstr);                     // full specialization for type const std::string&
    insert(coll, std::move(cstr));          // full specialization for type const std::string&&
}
