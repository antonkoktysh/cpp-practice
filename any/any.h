#pragma once

#include <type_traits>
#include <concepts>
#include <typeindex>
#include <iostream>

template <class T>
concept NotAny = !std::same_as<std::remove_cvref_t<T>, class Any>;

class Any {
private:
    struct Base {
        virtual ~Base() = default;
        virtual Base* ValueCopy() const = 0;
        explicit Base(std::type_index info) : info(info) {
        }
        std::type_index info;
    };

    template <typename T>
    struct Derived : public Base {
        T value;
        Derived(T value) : Base(typeid(T)), value(std::forward<T>(value)) {
        }
        ~Derived() = default;
        Base* ValueCopy() const override {
            return new Derived<T>(value);
        }
    };

    Base* ptr_ = nullptr;

public:
    Any() : ptr_(nullptr) {
    }

    // T&& - universal (forwarding) reference
    // use std::forward inside this constructor
    template <NotAny T>
    Any(T&& value) : ptr_(new Derived<std::remove_cvref_t<T>>(std::forward<T>(value))) {
    }
    // Any(T&& value) : ptr_(new Derived<T>(std::forward<T>(value))) {
    // }

    Any(const Any& other) {
        ptr_ = nullptr;
        if (other.ptr_) {
            ptr_ = other.ptr_->ValueCopy();
        }
    }

    Any(Any&& other) : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    Any& operator=(const Any& other) {
        if (this == &other) {
            return *this;
        }
        Base* temp = nullptr;
        Clear();
        if (other.ptr_ != nullptr) {
            temp = other.ptr_->ValueCopy();
        }
        this->~Any();

        ptr_ = temp;
        // if (other.ptr_ != nullptr) {
        //     this->~Any();
        //     Base* temp = nullptr;
        //     temp = other.ptr_->ValueCopy();
        //     ptr_ = temp;
        // } else {
        //     this->~Any();
        // }
        return *this;
    }

    Any& operator=(Any&& other) {
        this->~Any();
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        return *this;
    }

    ~Any() {
        delete ptr_;
        ptr_ = nullptr;
    }

    bool Empty() const {
        return !ptr_;
    }

    void Clear() {
        this->~Any();
    }

    void Swap(Any& other) {
        std::swap(ptr_, other.ptr_);
    }

    template <class T>
    const T& GetValue() const {
        if (!ptr_ || ptr_->info != typeid(T)) {
            throw std::bad_cast();
        }

        return static_cast<Derived<T>*>(ptr_)->value;
    }
};