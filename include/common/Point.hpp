#pragma once

#include <cmath>
#include <algorithm>

struct Point {
    int x,y;

};

inline int calcDistance(Point a, Point b) {
    return std::max(std::abs(a.x - b.x), std::abs(a.y - b.y));

}