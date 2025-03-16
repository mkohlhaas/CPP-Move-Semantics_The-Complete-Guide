#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// NOTE: both the move constructor and the move assignment operator should usually
// have a noexcept declaration when they are manually implemented.

class Customer
{
  private:
    std::string      name;   // name of customer
    std::vector<int> values; // some values of the customer

  public:
    Customer(const std::string &n) : name{n}
    {
        assert(!name.empty());
    }

    // ~Customer() = default; // automatic move semantics is disabled

    std::string
    getName() const
    {
        return name;
    }

    void
    addValue(int val)
    {
        values.push_back(val);
    }

    friend std::ostream &
    operator<<(std::ostream &strm, const Customer &cust)
    {
        strm << '[' << cust.name << ": ";
        for (int val : cust.values)
        {
            strm << val << ' ';
        }
        strm << ']';
        return strm;
    }

    // copy constructor (copy all members):
    // Customer(const Customer &cust) : name{cust.name}, values{cust.values}
    // {
    //     std::cout << "COPY " << cust.name << '\n';
    // }

    // move constructor (move all members):
    // NOTE:noexcept declaration missing!!!
    // Move semantics is not passed through!
    Customer(Customer &&cust) : name{std::move(cust.name)}, values{std::move(cust.values)}
    {
        std::cout << "MOVE " << name << '\n';
    }

    // copy assignment (assign all members):
    // Customer &
    // operator=(const Customer &cust)
    // {
    //     std::cout << "COPYASSIGN " << cust.name << '\n';
    //     name   = cust.name;
    //     values = cust.values;
    //     return *this;
    // }

    // move assignment (move all members):
    // NOTE:noexcept declaration missing!!!
    Customer &
    operator=(Customer &&cust)
    {
        std::cout << "MOVEASSIGN " << cust.name << '\n';
        name   = std::move(cust.name);   // move semantics is not passed through
        values = std::move(cust.values); // move semantics is not passed through
        return *this;
    }
};
