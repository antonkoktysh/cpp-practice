#pragma once

#include <string>
#include <stdexcept>
#include <algorithm>

std::string LongSum(const std::string& a, const std::string& b)
{
    std::string result;
    int rem = 0;
    for (size_t i = 0; i < std::max(a.size(), b.size()); ++i) {
        int value_a = 0;
        int value_b = 0;
        int res = rem;
        if (a.size() >= i + 1) {
            value_a = a[a.size() - i - 1] - '0';
        }
        if (b.size() >= i + 1) {
            value_b = b[b.size() - i - 1] - '0';
        }
        res += value_a + value_b;
        rem = res / 10;
        res %= 10;
        result.append(std::to_string(res));
    }
    if (rem != 0) {
        result.append(std::to_string(rem));
    }
    reverse(result.begin(), result.end());
    return result;

}
