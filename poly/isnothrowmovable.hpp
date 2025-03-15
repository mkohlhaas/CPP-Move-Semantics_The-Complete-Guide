// type trait to check whether a base class guarantees not to throw
// in the move constructor (even if the constructor is not callable)
#ifndef IS_NOTHROW_MOVABLE_HPP
#define IS_NOTHROW_MOVABLE_HPP

#include <type_traits>

template <typename Base>
struct Wrapper : Base
{
    using Base::Base;
    // implement all possibly wrapped pure virtual functions:
    void
    print() const
    {
    }
    //...
};

template <typename T>
static constexpr inline bool is_nothrow_movable_v = std::is_nothrow_move_constructible_v<Wrapper<T>>;

#endif // IS_NOTHROW_MOVABLE_HPP
