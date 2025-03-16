#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Customer
{
  private:
    std::string      _name;   // name of customer
    std::vector<int> _values; // some values of the customer

  public:
    Customer(const std::string &name) : _name{name}
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
};
