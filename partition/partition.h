#pragma once

#include <stdexcept>

template <typename Iterator>
void Swap(Iterator first, Iterator second) {
    auto temp = *first;
    *first = *second;
    *second = temp;
}

template <typename Iterator, typename Predicate>
Iterator Partition(Iterator first, Iterator last, Predicate pred) {
    Iterator pivot = first;
    for (Iterator it = first; it != last; ++it) {
        if (pred(*it)) {
            Swap(it, pivot);
            ++pivot;
        }
    }
    return pivot;
}
