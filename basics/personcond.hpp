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

    // print out when we copy or move:
    Person(const Person &p) : name{p.name}
    {
        std::cout << "COPY " << name << '\n';
    }
    Person(Person &&p) noexcept(std::is_nothrow_move_constructible<std::string>::value && noexcept(std::cout << name))
        : name{std::move(p.name)}
    {
        std::cout << "MOVE " << name << '\n';
    }
    //...
};
