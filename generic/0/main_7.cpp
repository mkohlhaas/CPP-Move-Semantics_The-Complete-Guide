#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
class Cont
{
  public:
    // primary template:
    template <typename U>
    void
    insert(U &&v) // universal reference
    {
        std::cout << "universal reference\n";
        coll.push_back(std::forward<U>(v));
    }

  private:
    std::vector<T> coll;
};

// full specializations for Cont<T>::insert<>() have to be outside the class
template <>
template <>
void
Cont<std::string>::insert<>(std::string &&v) // rvalue reference specialization
{
    std::cout << "rvalue reference\n";
    coll.push_back(std::move(v));
}

template <>
template <>
void
Cont<std::string>::insert<>(std::string &v) // lvalue reference specialization
{
    std::cout << "lvalue reference\n";
    coll.push_back(v);
}

int
main()
{
    Cont<std::string> c;

    c.insert("hello");              // universal reference
    c.insert(std::string{"hello"}); // rvalue reference

    std::string s{"hello again"};
    c.insert(s);                    // lvalue reference (passed by reference as v)
    c.insert(std::move(s));         // rvalue reference
}
