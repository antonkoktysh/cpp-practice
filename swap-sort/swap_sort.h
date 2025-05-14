#pragma once

#include <stdexcept>

void Swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Sort3(int* a, int* b, int* c) {
    if (*c > *b && *a > *b) {
        Swap(a, b);
    } else if (*b > *c && *a > *c) {
        Swap(a, c);
    }
    if (*b > *c) {
        Swap(b, c);
    }
}
