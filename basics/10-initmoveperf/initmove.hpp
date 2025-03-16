#pragma once

#include <string>

class Person
{
  private:
    std::string first; // first name
    std::string last;  // last name

  public:
    Person(std::string f, std::string l) : first{std::move(f)}, last{std::move(l)}
    {
    }
    //...
};
