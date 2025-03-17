#pragma once

#include <print>
#include <string>

class Person
{
  private:
    std::string name;

  public:
    // Person()
    // {
    // }

    Person(const char *name) : name{name}
    {
    }

    std::string
    getName() const
    {
        return name;
    }

    // print out when we copy or move:
    Person(const Person &p) : name{p.name}
    {
        std::println("COPY {}", name);
    }

    Person(Person &&p) : name{std::move(p.name)}
    {
        std::println("MOVE {}", name);
    }

    //...
};
