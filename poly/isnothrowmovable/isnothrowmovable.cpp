#include "isnothrowmovable.hpp"
#include <print>

// With noexcept, you can declare a (conditional) guarantee not to throw:
//
// - If you implement a move constructor, move assignment operator, or swap(), declare it with a (conditional) noexcept
//   expression.
// - For other functions, you might just want to mark them with an unconditional noexcept if they never throw.
// - Destructors are always declared with noexcept (even when implemented).

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
    // std::is_nothrow_move_constructible_v always yields false for abstract base classes
    std::println("std::is_nothrow_move_constructible_v<Base>: {}", std::is_nothrow_move_constructible_v<Base>); // false

    // Trick: wrap abstract class into a wrapper
    std::println("is_nothrow_movable_v<Base>: {}", is_nothrow_movable_v<Base>); // true
}
