#pragma once

#include <cassert>
#include <iostream>
#include <string>

void assertValidCard(const std::string &val);

class Card
{
  private:
    std::string value; // rank + "-of-" + suit

  public:
    Card(const std::string &v) : value{v}
    {
        assertValidCard(value); // ensure the value is always valid
    }

    std::string
    getValue() const
    {
        return value;
    }

    friend std::ostream &
    operator<<(std::ostream &strm, const Card &c)
    {
        return strm << c.value;
    }
};
