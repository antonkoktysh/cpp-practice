#pragma once

#include <stdexcept>
#include <cmath>
#include <algorithm>

enum class RootCount { kZero, kOne, kTwo, kInf };

struct Roots {
    RootCount count;
    double first;
    double second;
};

Roots SolveQuadratic(int a, int b, int c) {
    Roots res;
    if (a == 0) {
        if (b != 0) {
            res = {RootCount::kOne, static_cast<double>(-c) / b, 0};
        } else {
            if (c == 0) {
                res = Roots({RootCount::kInf, 0, 0});
            } else {
                res = Roots({RootCount::kZero, 0, 0});
            }
        }
    } else {
        if (b == 0) {
            if (static_cast<double>(-c) / a > 0) {
                res = Roots({RootCount::kTwo, -sqrt(static_cast<double>(-c) / a),
                             sqrt(static_cast<double>(-c) / a)});
            }
            if (c == 0) {
                res = Roots({RootCount::kOne, 0, 0});
            } else {
                res = Roots({RootCount::kZero, 0, 0});
            }
        }
        if (b != 0) {
            double d = b * b - 4 * a * c;
            if (d < 0) {
                res = Roots({RootCount::kZero, 0, 0});
            }
            if (d == 0) {
                res = Roots({RootCount::kOne, (-b + sqrt(d)) / (2 * a), 0});
            }
            if (d > 0) {
                double first_root = (-b - sqrt(d)) / (2 * a);
                double second_root = (-b + sqrt(d)) / (2 * a);
                res = Roots({RootCount::kTwo, std::min(first_root, second_root),
                             std::max(first_root, second_root)});
            }
        }
    }
    return res;
}
