#pragma once

#include <vector>
#include <stdexcept>
#include <cmath>

std::vector<int> Range(int from, int to, int step = 1) {
    std::vector<int> result;
    if (from < to && step > 0) {
        while (from < to) {
            result.push_back(from);
            from += step;
        }
    }
    if (from > to && step < 0) {
        while (from > to) {
            result.push_back(from);
            from += step;
        }
    }
    return result;
}
