#pragma once

#include <stdexcept>

struct Point {
    int64_t x, y;
};

struct Triangle {
    Point a, b, c;
};

Point GetVector(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

int64_t PseudoscalarProduct(const Point& a, const Point& b) {
    return a.x * b.y - b.x * a.y;
}

bool IsPointInTriangle(const Triangle& t, const Point& pt) {
    Point ab = GetVector(t.b, t.a);
    Point bc = GetVector(t.c, t.b);
    Point ca = GetVector(t.a, t.c);
    Point ao = GetVector(pt, t.a);
    Point bo = GetVector(pt, t.b);
    Point co = GetVector(pt, t.c);
    return (PseudoscalarProduct(ao, ab) >= 0 && PseudoscalarProduct(bo, bc) >= 0 &&
            PseudoscalarProduct(co, ca) >= 0) ||
           (PseudoscalarProduct(ao, ab) <= 0 && PseudoscalarProduct(bo, bc) <= 0 &&
            PseudoscalarProduct(co, ca) <= 0);
}
