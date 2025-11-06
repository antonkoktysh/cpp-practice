#pragma once

#include <algorithm>
#include <concepts>

template <typename Range, typename T>
concept HasFind = requires(Range range, T value) {
    { range.find(value) };
};

template <typename Range, typename T>
    requires HasFind<Range, T>
auto UniversalFind(const Range& range, T value) {
    return range.find(value);
}

template <typename Range, typename T>
auto UniversalFind(const Range& range, T value) {
    return std::ranges::find(range, value);
}