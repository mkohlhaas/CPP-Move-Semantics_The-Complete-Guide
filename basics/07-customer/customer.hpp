#include <iostream>
#include <print>
#include <string>

class Customer
{
  private:
    std::string name;

  public:
    Customer(std::string name) : name{name}
    {
        std::println("CONS {}", name);
    }

    // ~Customer() = default;

    std::string
    get_name() const
    {
        return name;
    }

    // copy constructor
    Customer(const Customer &cust) : name{cust.name}
    {
        std::cout << "COPY " << cust.name << '\n';
    }

    // move constructor
    Customer(Customer &&cust) : name{std::move(cust.name)}
    {
        std::cout << "MOVE " << name << '\n';
    }

    // copy assignment
    Customer &
    operator=(const Customer &cust)
    {
        std::cout << "COPYASSIGN " << cust.name << '\n';
        name = cust.name;
        return *this;
    }

    // move assignment
    Customer &
    operator=(Customer &&cust)
    {
        std::cout << "MOVEASSIGN " << cust.name << '\n';
        name = std::move(cust.name);
        return *this;
    }

    // move constructor/assignment declared as deleted will disable fallback to copying!!!:
    // Person(Person &&)            = delete;
    // Person &operator=(Person &&) = delete;

    // Customer(const Customer &)            = default;
    // Customer(Customer &&)                 = default;
    // Customer &operator=(const Customer &) = default;
    // Customer &operator=(Customer &&)      = default;
};
