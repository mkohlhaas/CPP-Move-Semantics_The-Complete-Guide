#include <cassert>
#include <iostream>
#include <string>

void assertValidCard(const std::string &val);

class Card
{
  private:
    std::string _value; // rank + "-of-" + suit

  public:
    Card(const std::string &v) : _value{v}
    {
        assertValidCard(_value); // ensure the value is always valid
    }
    //...

    std::string
    getValue() const
    {
        return _value;
    }

    friend std::ostream &
    operator<<(std::ostream &strm, const Card &c)
    {
        return strm << c._value;
    }
};
