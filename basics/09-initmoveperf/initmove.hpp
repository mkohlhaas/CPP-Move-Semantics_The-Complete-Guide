#pragma once

#include <string>

class Person
{
  private:
    std::string first_name;
    std::string last_name;

  public:
    // Not allowed: cannot bind non-const lvalue reference to an rvalue
    // Person(std::string &f, std::string &l) : first{std::move(f)}, last{std::move(l)} {}

    // Pass-by-value creates copies which will be moved to member vars!!!
    // Members first_name, last_name steal from f, l!!!
    // With this implementation of only one constructor any initialization is possible and cheap!!!
    Person(std::string f, std::string l) : first_name{std::move(f)}, last_name{std::move(l)}
    {
    }

    //...
};
