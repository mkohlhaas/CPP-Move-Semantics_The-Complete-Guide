#include "isnothrowmovable.hpp"
#include <iostream>

class Base
{
    std::string id;
    //...
  public:
    virtual void print() const = 0; // pure virtual function (forces abstract base class)
    //...
    virtual ~Base() = default;

  protected:
    // protected copy and move semantics (also forces abstract base class):
    Base(const Base &) = default;
    Base(Base &&)      = default;
    // disable assignment operator (due to the problem of slicing):
    Base &operator=(Base &&)      = delete;
    Base &operator=(const Base &) = delete;
};

int
main()
{
    std::cout << std::boolalpha;
    std::cout << "std::is_nothrow_move_constructible_v<Base>: " << std::is_nothrow_move_constructible_v<Base> << '\n';
    std::cout << "is_nothrow_movable_v<Base>:                 " << is_nothrow_movable_v<Base> << '\n';
}
