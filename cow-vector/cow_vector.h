#pragma once

#include <string>
#include <cstddef>

class COWVector {
public:
    struct State {
        std::size_t ref_count;
        std::size_t size;
        std::size_t capacity;
        std::string* data;

        ~State() {
            delete[] data;
        }
    };
    COWVector() : state_(new State(1, 0, 0, nullptr)) {
    }

    ~COWVector() {
        if (--state_->ref_count == 0) {
            delete state_;
        }
    }

    COWVector(const COWVector& other) : state_(other.state_) {
        ++state_->ref_count;
    }
    COWVector& operator=(const COWVector& other) {
        if (this != &other) {
            this->~COWVector();
            state_ = other.state_;
            ++state_->ref_count;
        }
        return *this;
    }

    size_t Size() const {
        return state_->size;
    }
    void Resize(size_t size) {
        if (size == state_->size) {
            return;
        }
        Detach();
        Reserve(size);
        state_->size = size;
    }
    const std::string& Get(size_t at) const {
        return state_->data[at];
    }
    const std::string& Back() const {
        return Get(Size() - 1);
    }
    void PushBack(const std::string& value) {
        Detach();
        if (state_->capacity == state_->size) {
            Reserve(state_->capacity == 0 ? 1 : state_->capacity * 2);
        }
        state_->data[Size()] = value;
        ++state_->size;
    }
    void Set(size_t at, const std::string& value) {
        Detach();
        state_->data[at] = value;
    }

private:
    void Detach() {
        if (state_->ref_count == 1) {
            return;
        }
        auto new_state =
            new State(1, state_->size, state_->capacity, new std::string[state_->capacity]);
        --state_->ref_count;
        if (state_->size > 0) {
            std::copy(state_->data, state_->data + state_->size, new_state->data);
        }
        state_ = new_state;
    }

    void Reserve(std::size_t capacity) {
        if (capacity <= state_->capacity) {
            return;
        }
        auto new_data = new std::string[capacity];
        std::copy(state_->data, state_->data + state_->size, new_data);
        delete[] state_->data;
        state_->capacity = capacity;
        state_->data = new_data;
    }
    State* state_;
};
