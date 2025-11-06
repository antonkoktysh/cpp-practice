#pragma once

#include <cstdint>
#include <map>
#include <stdexcept>
#include <utility>
#include <vector>

std::vector<std::pair<int64_t, int>> Factorize(int64_t x) {
    std::vector<std::pair<int64_t, int>> result;
    std::map<int64_t, int> map;
    int64_t bound = x;
    for (int64_t i = 2; i * i <= bound; ++i) {
        while (x % i == 0) {
            x /= i;
            ++map[i];
        }
    }
    if (x != 1) {
        ++map[x];
    }
    for (auto it : map) {
        result.emplace_back(it.first, it.second);
    }
    return result;
}
