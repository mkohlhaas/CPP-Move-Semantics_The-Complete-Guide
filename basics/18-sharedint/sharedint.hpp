#pragma once

#include <memory>
#include <string>

class SharedInt
{
  private:
    std::shared_ptr<int> sp;

    // used by moved-from objects
    inline static std::shared_ptr<int> movedFromValue{std::make_shared<int>(0)};

  public:
    explicit SharedInt(int val) : sp{std::make_shared<int>(val)}
    {
    }

    std::string
    asString() const
    {
        return std::to_string(*sp); // OOPS: unconditional deref -> crash
    }

    // Uncomment following lines to prevent crash during runtime!

    // SharedInt(SharedInt &&si) : sp{std::move(si.sp)}
    // {
    //     si.sp = movedFromValue;
    // }
    //
    // SharedInt &
    // operator=(SharedInt &&si) noexcept
    // {
    //     if (this != &si)
    //     {
    //         sp    = std::move(si.sp);
    //         si.sp = movedFromValue;
    //     }
    //     return *this;
    // }
    //
    // SharedInt(const SharedInt &)            = default;
    // SharedInt &operator=(const SharedInt &) = default;
};
