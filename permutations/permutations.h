#pragma once

#include <vector>
#include <stdexcept>

std::vector<std::vector<int>> GeneratePermutations(size_t len) {
    std::vector<std::vector<int>> result;
    if (len == 1) {
        return std::vector<std::vector<int>>(1, std::vector<int>(1, 0));
    }
    std::vector<int> current_permutation(len);
    for (size_t i = 0; i < len; ++i) {
        current_permutation[i] = i;
    }
    while (true) {
        result.push_back(current_permutation);
        int i = len - 2;
        while (i >= 0) {
            if (current_permutation[i] < current_permutation[i + 1]) {
                break;
            }
            --i;
        }
        if (i == -1) {
            break;
        }
        int j = len - 1;
        while (j > i) {
            if (current_permutation[j] > current_permutation[i]) {
                break;
            }
            --j;
        }
        std::swap(current_permutation[i], current_permutation[j]);
        for (size_t l = 0; l < (len - i) / 2; ++l) {
            std::swap(current_permutation[i + 1 + l], current_permutation[len - 1 - l]);
        }
    }
    return result;
}