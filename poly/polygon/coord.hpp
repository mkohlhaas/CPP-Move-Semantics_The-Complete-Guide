#pragma once

#include <iostream>

class Coord
{
  private:
    int x{0}; // x coordinate
    int y{0}; // y coordinate

  public:
    // default constructor:
    Coord() = default;

    // other constructor:
    Coord(int xarg, int yarg) : x{xarg}, y{yarg}
    {
    }

    friend Coord
    operator+(Coord c1, Coord c2)
    {
        return Coord{c1.x + c2.x, c1.y + c2.y};
    }

    friend Coord
    operator-(Coord c1, Coord c2)
    {
        return Coord{c1.x - c2.x, c1.y - c2.y};
    }

    Coord
    operator-() const
    {
        return Coord{-x, -y};
    }
    void
    operator+=(Coord c)
    {
        *this = *this + c;
    }

    void
    operator-=(Coord c)
    {
        operator+=(-c);
    }

    int
    getX() const
    {
        return x;
    }

    int
    getY() const
    {
        return y;
    }

    friend std::ostream &
    operator<<(std::ostream &strm, Coord c)
    {
        return strm << '(' << c.x << ',' << c.y << ')';
    }
};
