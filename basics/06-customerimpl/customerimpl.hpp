#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// NOTE: both the move constructor and the move assignment operator should usually
// have a noexcept declaration when they are manually implemented.

class Customer
{
  private:
    std::string      _name;   // name of the customer
    std::vector<int> _values; // some values of the customer
  public:
    Customer(const std::string &n) : _name{n}
    {
        assert(!_name.empty());
    }

    std::string
    getName() const
    {
        return _name;
    }

    void
    addValue(int val)
    {
        _values.push_back(val);
    }

    friend std::ostream &
    operator<<(std::ostream &strm, const Customer &cust)
    {
        strm << '[' << cust._name << ": ";
        for (int val : cust._values)
        {
            strm << val << ' ';
        }
        strm << ']';
        return strm;
    }

    // copy constructor (copy all members):
    Customer(const Customer &cust) : _name{cust._name}, _values{cust._values}
    {
        std::cout << "COPY " << cust._name << '\n';
    }

    // move constructor (move all members):
    // NOTE:noexcept declaration missing!!!
    // Move semantics is not passed through!
    Customer(Customer &&cust) : _name{std::move(cust._name)}, _values{std::move(cust._values)}
    {
        std::cout << "MOVE " << _name << '\n';
    }

    // copy assignment (assign all members):
    Customer &
    operator=(const Customer &cust)
    {
        std::cout << "COPYASSIGN " << cust._name << '\n';
        _name   = cust._name;
        _values = cust._values;
        return *this;
    }

    // move assignment (move all members):
    // NOTE:noexcept declaration missing!!!
    Customer &
    operator=(Customer &&cust)
    {
        std::cout << "MOVEASSIGN " << cust._name << '\n';
        _name   = std::move(cust._name);   // move semantics is not passed through
        _values = std::move(cust._values); // move semantics is not passed through
        return *this;
    }
};
