#pragma once

#include <print>
#include <string>

class Person
{
  private:
    std::string name;

  public:
    Person(const char *n) : name{n}
    {
    }

    std::string
    getName() const
    {
        return name;
    }

    Person(const Person &p) : name{p.name}
    {
        std::println("COPY {}", name);
    }

    // force default generated move constructor
    // The compiler will detect noexcept guarantees for you if you do not implement the move constructor yourself.
    // For classes where all members guarantee not to throw in the move constructor, a generated or defaulted move
    // constructor will give the guarantee as a whole.
    Person(Person &&p) = default;

    //...
};
