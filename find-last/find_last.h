#pragma once

#include <stdexcept>

template <class Iterator, class T>
Iterator FindLast(Iterator first, Iterator last, const T& value) {
    auto ans = last;
    for (auto it = first; it != last; ++it) {
        if (*it == value) {
            ans = it;
        }
    }
    return ans;
}
