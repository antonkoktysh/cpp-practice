#pragma once

#include <cstddef>
#include <vector>
#include <cstdint>

class RingBuffer {
    std::vector<int> queue_;
    size_t capacity_;
    size_t size_;
    size_t first_index_;
    size_t last_index_;

public:
    explicit RingBuffer(const size_t capacity)
        : capacity_(capacity), size_(0), first_index_(0), last_index_(0) {
        queue_.resize(capacity);
    }

    size_t Size() const {
        return size_;
    }

    bool Empty() const {
        return size_ == 0;
    }

    bool TryPush(int element) {
        if (Size() == capacity_) {
            return false;
        }
        queue_[last_index_] = element;
        last_index_ = (last_index_ + 1) % capacity_;
        ++size_;
        return true;
    }

    bool TryPop(int* element) {
        if (Empty()) {
            return false;
        }

        *element = queue_[first_index_];
        first_index_ = (first_index_ + 1) % capacity_;
        --size_;
        return true;
    }
};
