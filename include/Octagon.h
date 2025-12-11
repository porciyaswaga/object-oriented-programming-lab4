#ifndef LAB04_OCTAGON_H
#define LAB04_OCTAGON_H

#include "Figure.h"
#include <cmath>

template <std::floating_point T>
class Octagon : public Figure<T> {
private:
    Point<T> center;
    T r;

public:
    Octagon(T cx, T cy, T radius) : center(cx, cy), r(radius) {}

    T area() const override {
        return 2 * (1 + std::sqrt(2)) * r * r;
    }

    Point<T> geometricCenter() const override {
        return center;
    }

    std::vector<Point<T>> getVertices() const override {
        std::vector<Point<T>> v(8);
        for (int i = 0; i < 8; i++) {
            T angle = M_PI / 4 * i;
            v[i] = Point<T>(
                center.x + r * std::cos(angle),
                center.y + r * std::sin(angle)
            );
        }
        return v;
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Octagon<T>>(center.x, center.y, r);
    }
};

#endif
