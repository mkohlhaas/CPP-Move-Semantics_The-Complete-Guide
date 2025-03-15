#include <iostream>
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

    // print out when we copy:
    Person(const Person &p) : name{p.name}
    {
        std::cout << "COPY " << name << '\n';
    }
    // force default generated move constructor:
    Person(Person &&p) = default;
    //...
};
