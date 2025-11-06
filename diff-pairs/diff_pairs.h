#pragma once

#include <vector>
#include <cstdint>
#include <stdexcept>
#include <unordered_map>

int64_t CountPairs(const std::vector<int>& data, int x) {
    std::unordered_map<int, int> map;
    int64_t ans = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        int64_t target = static_cast<int64_t>(x) - static_cast<int64_t>(data[i]);
        if (map.count(target)) {
            ans += map[x - data[i]];
        }
        if (!map.count(data[i])) {
            map.insert(std::make_pair(data[i], 1));
        } else {
            ++map[data[i]];
        }
    }
    return ans;
}
