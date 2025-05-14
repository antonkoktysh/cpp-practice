    #pragma once

#include <string>
#include <cstddef>
#include <catch2/catch_test_macros.hpp>
class WeakPtr;

class ControlBlock {
public:
    ControlBlock(std::string* ptr, size_t strong_count, size_t weak_count)
        : ptr_(ptr), weak_count_(weak_count), strong_count_(strong_count) {
    }
    ControlBlock() : weak_count_(0U), strong_count_(0U) {
    }
    void WeakIncrement() {
        ++weak_count_;
    }
    void WeakDecrement() {
        if (weak_count_ == 0U) {
            return;
        }
        --weak_count_;
    }
    void StrongIncrement() {
        ++strong_count_;
    }
    void StrongDecrement() {
        if (strong_count_ == 0U) {
            return;
        }
        --strong_count_;
    }
    size_t GetWeak() const {
        return weak_count_;
    }
    size_t GetStrong() const {
        return strong_count_;
    }

public:
    std::string* ptr_;
    size_t weak_count_;
    size_t strong_count_;
};

class SharedPtr {
public:
    SharedPtr() : control_block_(nullptr) {
    }

    SharedPtr(const WeakPtr& ptr);

    SharedPtr(std::string* ptr) {
        if (ptr != nullptr) {
            control_block_ = new ControlBlock{ptr, 1U, 0U};
        } else {
            control_block_ = nullptr;
        }
    }

    SharedPtr(const SharedPtr& other) : control_block_(other.control_block_) {
        if (control_block_ && control_block_->ptr_ != nullptr) {
            ++control_block_->strong_count_;
        }
    }

    SharedPtr(SharedPtr&& other) noexcept : control_block_(other.control_block_) {
        other.control_block_ = nullptr;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this == &other) {
            return *this;
        }
        this->~SharedPtr();
        control_block_ = other.control_block_;
        if (control_block_ && control_block_->ptr_ != nullptr) {
            ++control_block_->strong_count_;
        }
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        this->~SharedPtr();
        control_block_ = other.control_block_;
        other.control_block_ = nullptr;
        return *this;
    }
    // ?
    ~SharedPtr() {
        if (control_block_ != nullptr) {
            control_block_->StrongDecrement();
            if (control_block_->GetStrong() == 0U) {
                delete control_block_->ptr_;
                if (control_block_->GetWeak() == 0) {
                    delete control_block_;
                }
            }
        }
    }

    void Reset(std::string* ptr) {
        this->~SharedPtr();
        if (ptr) {
            control_block_ = new ControlBlock{ptr, 1, 0};
        } else {
            control_block_ = nullptr;
        }
    }

    std::string& operator*() const {
        return *control_block_->ptr_;
    }

    std::string* operator->() const {
        return control_block_->ptr_;
    }

    std::string* Get() const {
        if (control_block_) {
            return control_block_->ptr_;
        }
        return nullptr;
    }

private:
    ControlBlock* control_block_;
    friend class WeakPtr;
};

class WeakPtr {
public:
    WeakPtr(const SharedPtr& other) : control_block_(other.control_block_) {
        if (control_block_ && control_block_->ptr_ != nullptr) {
            control_block_->WeakIncrement();
        }
    }

    WeakPtr() : control_block_(nullptr) {
    }

    WeakPtr(WeakPtr&& other) : control_block_(other.control_block_) {
        other.control_block_ = nullptr;
    }

    WeakPtr(const WeakPtr& other) : control_block_(other.control_block_) {
        if (control_block_ && control_block_->ptr_) {
            ++control_block_->weak_count_;
        }
    }

    WeakPtr& operator=(const WeakPtr& other) {
        if (this == &other) {
            return *this;
        }
        this->~WeakPtr();
        control_block_ = other.control_block_;
        if (control_block_ && control_block_->ptr_) {
            ++control_block_->weak_count_;
        }
        return *this;
    }

    bool IsExpired() const {
        return !control_block_ || control_block_->GetStrong() == 0U;
    }

    SharedPtr Lock() const {
        SharedPtr ptr(*this);
        return ptr;
    }

    std::string* Get() const {
        return (control_block_->ptr_);
    }

    std::string* operator->() const {
        return control_block_->ptr_;
    }

    std::string& operator*() {
        return *control_block_->ptr_;
    }

    ~WeakPtr() {
        if (control_block_) {
            if (control_block_->ptr_) {
                --control_block_->weak_count_;
            }
            if (control_block_->strong_count_ == 0U && control_block_->weak_count_ == 0U) {
                delete control_block_;
            }
        }
    }

private:
    ControlBlock* control_block_;
    friend class SharedPtr;
};

SharedPtr::SharedPtr(const WeakPtr& other) : control_block_(other.control_block_) {
    if (!other.IsExpired()) {
        control_block_ = other.control_block_;
        ++control_block_->strong_count_;
    } else {
        control_block_ = nullptr;
    }
}
