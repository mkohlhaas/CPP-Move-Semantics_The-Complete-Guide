#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Customer
{
  private:
    std::string      name;   // name of customer
    std::vector<int> values; // some values of the customer

  public:
    Customer(const std::string &name) : name{name}
    {
        assert(!name.empty());
    }

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
};
