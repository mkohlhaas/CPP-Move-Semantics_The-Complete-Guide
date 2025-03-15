#include "polygon.hpp"
#include "geoobj.hpp"

int
main()
{
    Polygon p0{"Poly1", {Coord{1, 1}, Coord{1, 9}, Coord{9, 9}, Coord{9, 1}}};
    Polygon p1{p0};            // copy
    Polygon p2{std::move(p0)}; // move

    p0.draw();
    p1.draw();
    p2.draw();
}
