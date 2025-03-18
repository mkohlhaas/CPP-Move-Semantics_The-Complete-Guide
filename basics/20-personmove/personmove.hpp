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

    // noexcept allows move semantics on reallocations
    Person(Person &&p) noexcept : name{std::move(p.name)}
    {
        std::println("MOVE ", name);
    }

    //...
};
