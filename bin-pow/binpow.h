#pragma once

#include <stdexcept>

int BinPow(int a, int64_t b, int c) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        int64_t res = BinPow(a, b / 2, c);
        return (res * res) % c;
    } else {
        int64_t res = BinPow(a, b - 1, c);
        return (a * res) % c;
    }
}