#pragma once

#include <string>

class Person
{
  private:
    std::string first_name;
    std::string last_name;

  public:
    Person(const std::string &first_name, const std::string &last_name) : first_name{first_name}, last_name{last_name}
    {
    }

    //...
};
