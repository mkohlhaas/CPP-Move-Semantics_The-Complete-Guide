#include <cassert>
#include <iostream>
#include <string>

// class for email addresses
// - asserts that each email address has a @
// - except when in a moved-from state
class Email
{
  private:
    std::string value;            // email address
    bool        movedFrom{false}; // special moved-from state
  public:
    Email(const std::string &val) : value{val}
    {
        assert(value.find('@') != std::string::npos);
    }
    Email(const char *val) // enable implicit conversions for string literals
        : Email{std::string(val)}
    {
    }

    std::string
    getValue() const
    {
        assert(!movedFrom); // or throw
        return value;
    }
    //...

    // implement move operations to signal a moved-from state:
    Email(Email &&e) noexcept : value{std::move(e.value)}, movedFrom{e.movedFrom}
    {
        e.movedFrom = true;
    }
    Email &
    operator=(Email &&e) noexcept
    {
        value       = std::move(e.value);
        movedFrom   = e.movedFrom;
        e.movedFrom = true;
        return *this;
    }
    // enable copying:
    Email(const Email &)            = default;
    Email &operator=(const Email &) = default;

    // print out the current state (even if it is a moved-from state):
    friend std::ostream &
    operator<<(std::ostream &strm, const Email &e)
    {
        return strm << (e.movedFrom ? "MOVED-FROM" : e.value);
    }
};
