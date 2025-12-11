#include <gtest/gtest.h>
#include "Triangle.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Array.h"

TEST(TriangleTest, Area) {
    Triangle<double> t(0,0, 4,0, 0,3);
    EXPECT_NEAR(t.area(), 6.0, 1e-6);
}

TEST(HexagonTest, Area) {
    Hexagon<double> h(0,0, 2);
    EXPECT_NEAR(h.area(), (3*sqrt(3)/2)*4, 1e-6);
}

TEST(OctagonTest, Area) {
    Octagon<double> o(0,0, 1);
    EXPECT_NEAR(o.area(), 2 * (1 + sqrt(2)), 1e-6);
}

TEST(FigureCastTest, Cast) {
    Hexagon<double> h(0,0,1);
    double a = static_cast<double>(h);
    EXPECT_NEAR(a, (3*sqrt(3)/2), 1e-6);
}

TEST(ArrayTest, PushRemove) {
    Array<int> arr;
    arr.push_back(5);
    arr.push_back(7);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 5);

    arr.removeAt(0);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 7);
}
