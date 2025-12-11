#ifndef LAB04_FIGURE_H
#define LAB04_FIGURE_H

#include "Point.h"
#include <memory>
#include <vector>
#include <iostream>

template <std::floating_point T>
class Figure {
public:
    using point_ptr = std::unique_ptr<Point<T>>;

    virtual ~Figure() = default;

    virtual T area() const = 0;
    virtual Point<T> geometricCenter() const = 0;
    virtual std::vector<Point<T>> getVertices() const = 0;

    explicit operator double() const {
        return static_cast<double>(area());
    }

    virtual std::unique_ptr<Figure<T>> clone() const = 0;

    bool operator==(const Figure<T>& other) const {
        return area() == other.area();
    }
    bool operator!=(const Figure<T>& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& fig) {
        os << "Центр: " << fig.geometricCenter()
           << ", Площадь: " << fig.area()
           << ", Вершины: ";
        auto verts = fig.getVertices();
        for (size_t i = 0; i < verts.size(); ++i) {
            os << verts[i];
            if (i != verts.size() - 1) os << ", ";
        }
        return os;
    }
};

#endif
