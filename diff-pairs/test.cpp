#include "diff_pairs.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Your tests here") {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(-1);
    vec.push_back(5);
    CHECK(CountPairs(vec, 6) == 3);
}