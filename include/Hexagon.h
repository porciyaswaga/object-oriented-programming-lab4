#ifndef LAB04_HEXAGON_H
#define LAB04_HEXAGON_H

#include "Figure.h"
#include <cmath>

template <std::floating_point T>
class Hexagon : public Figure<T> {
private:
    Point<T> center;
    T r;

public:
    Hexagon(T cx, T cy, T radius) : center(cx, cy), r(radius) {}

    T area() const override {
        return (3 * std::sqrt(3) / 2) * r * r;
    }

    Point<T> geometricCenter() const override {
        return center;
    }

    std::vector<Point<T>> getVertices() const override {
        std::vector<Point<T>> v(6);
        for (int i = 0; i < 6; i++) {
            T angle = M_PI / 3 * i;
            v[i] = Point<T>(
                center.x + r * std::cos(angle),
                center.y + r * std::sin(angle)
            );
        }
        return v;
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Hexagon<T>>(center.x, center.y, r);
    }
};

#endif
