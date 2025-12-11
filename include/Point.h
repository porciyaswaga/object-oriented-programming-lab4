#ifndef LAB04_POINT_H
#define LAB04_POINT_H

#include <concepts>
#include <iostream>

template <std::floating_point T>
class Point {
public:
    T x, y;

    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

#endif
