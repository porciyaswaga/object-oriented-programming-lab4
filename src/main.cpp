#include <iostream>
#include <memory>

#include "Point.h"
#include "Figure.h"
#include "Triangle.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Array.h"

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;

    std::cout << "Создаём фигуры...\n";

    figures.push_back(std::make_shared<Triangle<double>>(
        Point<double>(0, 0),
        Point<double>(4, 0),
        Point<double>(2, 3)
    ));

    figures.push_back(std::make_shared<Hexagon<double>>(0.0, 0.0, 2.0));
    figures.push_back(std::make_shared<Octagon<double>>(1.0, 1.0, 1.5));

    std::cout << "\n=== Содержимое массива фигур ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << i << ": " << *figures[i] << "\n";
    }

    double total = 0;
    for (auto& f : figures) total += static_cast<double>(*f);

    std::cout << "\nОбщая площадь всех фигур: " << total << "\n";

    std::cout << "\nУдаляем фигуру под индексом 1...\n";
    figures.removeAt(1);

    std::cout << "\n=== Содержимое массива после удаления ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << i << ": " << *figures[i] << "\n";
    }

    total = 0;
    for (auto& f : figures) total += static_cast<double>(*f);
    std::cout << "\nОбщая площадь после удаления: " << total << "\n";
    return 0;
}
