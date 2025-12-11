#ifndef LAB04_TRIANGLE_H
#define LAB04_TRIANGLE_H

#include "Figure.h"
#include <cmath>

template <std::floating_point T>
class Triangle : public Figure<T> {
private:
    Point<T> a, b, c;

public:
    Triangle(T x1, T y1, T x2, T y2, T x3, T y3)
        : a(x1, y1), b(x2, y2), c(x3, y3) {}

    Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3)
        : a(p1), b(p2), c(p3) {}

    T area() const override {
        return std::abs(
            (a.x * (b.y - c.y) +
             b.x * (c.y - a.y) +
             c.x * (a.y - b.y)) / 2
        );
    }

    Point<T> geometricCenter() const override {
        return Point<T>((a.x + b.x + c.x) / 3,
                        (a.y + b.y + c.y) / 3);
    }

    std::vector<Point<T>> getVertices() const override {
        return {a, b, c};
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Triangle<T>>(a, b, c);
    }
};

#endif
