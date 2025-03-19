#include <iostream>
#include <print>
#include <string>
#include <utility>

// std::forward<>() for Calling Member Functions

class Person
{
  private:
    std::string name;

  public:
    void
    print() const
    {
        std::cout << "print()\n";
    }

    std::string
    getName() &&
    {
        // when we no longer need the value we steal and return by value
        return std::move(name);
    }

    const std::string &
    getName() const &
    {
        // in all other cases we give access to the member
        return name;
    }
};

// in a function that takes a universal reference, we might benefit from using std::forward<>()
template <typename T>
void
foo(T &&x)
{
    x.print();                    // OK, no need to forward the passed value category
    x.getName();                  // calls getName() const&
    std::forward<T>(x).getName(); // calls getName() && for rvalues (OK, no longer need x)
}

// After using std::forward<>(), x is in a valid but unspecified state.Whenever you use std::forward<>(), make sure you
// do no longer use(the value of) the object.
