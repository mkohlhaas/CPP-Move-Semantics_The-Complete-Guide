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
        std::println("COPY ", name);
    }

    Person(Person &&p) noexcept(std::is_nothrow_move_constructible<std::string>::value &&
                                noexcept(std::println("{}", name)))
        : name{std::move(p.name)}
    {
        std::println("MOVE ", name);
    }

    //...
};
