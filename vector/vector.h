#pragma once

#include <cstdint>
#include <iterator>
#include <cstddef>

class Vector {
public:
    class Iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = int;
        using difference_type = ptrdiff_t;
        using pointer = int*;
        using reference = int&;

        Iterator() : ptr_(nullptr) {
        }

        Iterator(pointer value) : ptr_(value) {
        }

        Iterator& operator+=(difference_type val) {
            ptr_ += val;
            return *this;
        }

        Iterator& operator++() {
            ptr_ += 1U;
            return *this;
        }

        Iterator operator++(value_type) {
            Iterator to_return = *this;
            ptr_ += 1U;
            return to_return;
        }

        Iterator& operator--() {
            ptr_ -= 1U;
            return *this;
        }

        Iterator operator--(value_type) {
            Iterator to_return = *this;
            ptr_ -= 1U;
            return to_return;
        }

        pointer operator->() const {
            return ptr_;
        }

        reference operator*() const {
            return *ptr_;
        }

        Iterator operator+(difference_type val) const {
            Iterator iter = *this;
            iter += val;
            return iter;
        }

        Iterator& operator-=(difference_type val) {
            ptr_ -= val;
            return *this;
        }

        Iterator operator-(difference_type val) const {
            Iterator iter = *this;
            iter -= val;
            return iter;
        }

        difference_type operator-(const Iterator& other) const {
            return ptr_ - other.ptr_;
        }

        reference operator[](difference_type index) const {
            return *(ptr_ + index);
        }

        friend Iterator operator+(difference_type val, Iterator iterator) {
            return Iterator(iterator.ptr_ + val);
        }

        friend Iterator operator-(difference_type val, Iterator iterator) {
            return Iterator(iterator.ptr_ - val);
        }

        auto operator<=>(const Iterator&) const = default;

    private:
        pointer ptr_;
    };

    Vector() : size_(0U), capacity_(0U), data_(nullptr) {
    }

    Vector(size_t size) : size_(size), capacity_(size), data_(new int[capacity_]) {
        for (size_t ind = 0U; ind < size_; ++ind) {
            data_[ind] = 0;
        }
    }

    Vector(std::initializer_list<int> vec) : Vector(vec.size()) {
        size_t index = 0U;
        for (auto el : vec) {
            data_[index++] = el;
        }
    }

    Vector(const Vector& other)
        : size_(other.size_), capacity_(other.capacity_), data_(new int[capacity_]) {
        for (size_t ind = 0U; ind < size_; ++ind) {
            data_[ind] = other.data_[ind];
        }
    }

    Vector(Vector&& other) : size_(other.Size()), capacity_(other.Capacity()), data_(other.data_) {
        other.data_ = nullptr;
        other.size_ = 0U;
        other.capacity_ = 0U;
    }

    ~Vector() {
        delete[] data_;
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data_;
        data_ = new int[other.Capacity()];
        size_ = other.Size();
        capacity_ = other.Capacity();
        for (size_t ind = 0U; ind < size_; ++ind) {
            data_[ind] = other.data_[ind];
        }
        return *this;
    }

    Vector& operator=(Vector&& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data_;
        data_ = other.data_;
        other.data_ = nullptr;
        size_ = other.Size();
        other.size_ = 0U;
        capacity_ = other.Capacity();
        other.capacity_ = 0U;
        return *this;
    }

    int operator[](size_t ind) const {
        return data_[ind];
    }

    int& operator[](size_t ind) {
        return data_[ind];
    }

    Iterator begin() {
        return Iterator(data_);
    }

    Iterator end() {
        return Iterator(data_ + size_);
    }

    size_t Size() const {
        return size_;
    }

    size_t Capacity() const {
        return capacity_;
    }

    bool Empty() const {
        return Size() == 0U;
    }

    void PushBack(int val) {
        if (size_ == capacity_) {
            Reserve(capacity_ > 0 ? capacity_ * 2 : 1);
        }
        ++size_;
        data_[size_ - 1U] = val;
    }

    void PopBack() {
        if (Empty()) {
            return;
        }
        --size_;
    }

    void Reserve(size_t capacity) {
        if (capacity_ >= capacity) {
            return;
        }
        capacity_ = capacity;
        int* new_data = new int[capacity];
        for (size_t ind = 0U; ind < size_; ++ind) {
            new_data[ind] = data_[ind];
        }
        delete[] data_;
        data_ = new_data;
    }

    void Clear() {
        size_ = 0U;
    }

    void Swap(Vector& other) {
        int* temp = other.data_;
        other.data_ = data_;
        data_ = temp;
        temp = nullptr;

        size_t temp_size = other.size_;
        other.size_ = size_;
        size_ = temp_size;

        size_t temp_cap = other.capacity_;
        other.capacity_ = capacity_;
        capacity_ = temp_cap;
    }

private:
    size_t size_;
    size_t capacity_;
    int* data_;
};