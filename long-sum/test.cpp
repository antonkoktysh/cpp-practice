#include "long_sum.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Your test") {
    CHECK(LongSum("2", "2") == "4");
}

TEST_CASE("Simple") {
    CHECK(LongSum("500", "500") == "1000");
}
