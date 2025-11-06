#pragma once

#include <cstddef>
#include <utility>

template <typename T>
class WeakPtr;

template <typename T>
struct DefaultDeleter {
    void operator()(T* ptr) const;
};

template <typename T>
struct DefaultDeleter<T[]> {
    void operator()(T* ptr) const;
};

template <typename T>
class ControlBlockBase {
public:
    ControlBlockBase(T* ptr, size_t strong_count, size_t weak_count);
    virtual ~ControlBlockBase();

    virtual void DeleteObject() = 0;

    void WeakIncrement();
    void WeakDecrement();
    void StrongIncrement();
    void StrongDecrement();
    size_t GetWeak() const;
    size_t GetStrong() const;

    T* ptr_;

protected:
    size_t weak_count_;
    size_t strong_count_;
};

template <typename T>
ControlBlockBase<T>::ControlBlockBase(T* ptr, size_t strong_count, size_t weak_count)
    : ptr_(ptr), strong_count_(strong_count), weak_count_(weak_count) {
}

template <typename T>
ControlBlockBase<T>::~ControlBlockBase() = default;

template <typename T>
void ControlBlockBase<T>::WeakIncrement() {
    ++weak_count_;
}

template <typename T>
void ControlBlockBase<T>::WeakDecrement() {
    if (weak_count_ > 0)
        --weak_count_;
}

template <typename T>
void ControlBlockBase<T>::StrongIncrement() {
    ++strong_count_;
}

template <typename T>
void ControlBlockBase<T>::StrongDecrement() {
    if (strong_count_ > 0)
        --strong_count_;
}

template <typename T>
size_t ControlBlockBase<T>::GetWeak() const {
    return weak_count_;
}

template <typename T>
size_t ControlBlockBase<T>::GetStrong() const {
    return strong_count_;
}

template <typename T, typename Deleter>
class ControlBlockWithDeleter : public ControlBlockBase<T> {
public:
    ControlBlockWithDeleter(T* ptr, Deleter deleter, size_t strong_count, size_t weak_count);
    void DeleteObject() override;

private:
    Deleter deleter_;
};

template <typename T, typename Deleter>
ControlBlockWithDeleter<T, Deleter>::ControlBlockWithDeleter(T* ptr, Deleter deleter,
                                                             size_t strong_count, size_t weak_count)
    : ControlBlockBase<T>(ptr, strong_count, weak_count), deleter_(deleter) {
}

template <typename T, typename Deleter>
void ControlBlockWithDeleter<T, Deleter>::DeleteObject() {
    deleter_(this->ptr_);
}

template <typename T>
class SharedPtr {
public:
    SharedPtr();
    template <typename Deleter = DefaultDeleter<T>>
    SharedPtr(T* ptr, Deleter deleter = DefaultDeleter<T>());
    SharedPtr(const WeakPtr<T>& other);
    SharedPtr(const SharedPtr& other);
    SharedPtr(SharedPtr&& other) noexcept;
    ~SharedPtr();

    SharedPtr& operator=(const SharedPtr& other);
    SharedPtr& operator=(SharedPtr&& other) noexcept;

    template <typename Deleter = DefaultDeleter<T>>
    void Reset(T* ptr = nullptr, Deleter deleter = DefaultDeleter<T>());

    T& operator*() const;
    T* operator->() const;
    T* Get() const;
    explicit operator bool() const;
    size_t UseCount() const;

private:
    template <typename U, typename... Args>
    friend SharedPtr<U> MakeShared(Args&&...);
    ControlBlockBase<T>* control_block_;
    friend class WeakPtr<T>;
    SharedPtr(ControlBlockBase<T>* control_block);
};

template <typename T>
SharedPtr<T>::SharedPtr() : control_block_(nullptr) {
}

template <typename T>
template <typename Deleter>
SharedPtr<T>::SharedPtr(T* ptr, Deleter deleter) {
    if (ptr) {
        control_block_ = new ControlBlockWithDeleter<T, Deleter>(ptr, deleter, 1, 0);
    } else {
        control_block_ = nullptr;
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other) : control_block_(other.control_block_) {
    if (control_block_) {
        control_block_->StrongIncrement();
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr&& other) noexcept : control_block_(other.control_block_) {
    other.control_block_ = nullptr;
}

template <typename T>
SharedPtr<T>::~SharedPtr() {
    Reset();
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other) {
    if (this == &other) {
        return *this;
    }
    Reset();
    control_block_ = other.control_block_;
    if (control_block_) {
        control_block_->StrongIncrement();
    }
    return *this;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr&& other) noexcept {
    if (this == &other)
        return *this;
    Reset();
    control_block_ = other.control_block_;
    other.control_block_ = nullptr;
    return *this;
}

template <typename T>
template <typename Deleter>
void SharedPtr<T>::Reset(T* ptr, Deleter deleter) {
    if (control_block_) {
        control_block_->StrongDecrement();
        if (control_block_->GetStrong() == 0) {
            control_block_->DeleteObject();
            if (control_block_->GetWeak() == 0) {
                delete control_block_;
            }
        }
    }

    if (ptr) {
        control_block_ = new ControlBlockWithDeleter<T, Deleter>(ptr, deleter, 1, 0);
    } else {
        control_block_ = nullptr;
    }
}

template <typename T>
T& SharedPtr<T>::operator*() const {
    return *control_block_->ptr_;
}

template <typename T>
T* SharedPtr<T>::operator->() const {
    return control_block_->ptr_;
}

template <typename T>
T* SharedPtr<T>::Get() const {
    return control_block_ ? control_block_->ptr_ : nullptr;
}

template <typename T>
SharedPtr<T>::operator bool() const {
    return control_block_ && control_block_->ptr_;
}

template <typename T>
size_t SharedPtr<T>::UseCount() const {
    return control_block_ ? control_block_->GetStrong() : 0;
}

template <typename T>
class WeakPtr {
public:
    WeakPtr();
    WeakPtr(const SharedPtr<T>& other);
    WeakPtr(const WeakPtr& other);
    WeakPtr(WeakPtr&& other) noexcept;
    ~WeakPtr();

    WeakPtr& operator=(const WeakPtr& other);
    WeakPtr& operator=(const SharedPtr<T>& other);
    WeakPtr& operator=(WeakPtr&& other) noexcept;

    bool IsExpired() const;
    SharedPtr<T> Lock() const;
    void Reset();
    size_t UseCount() const;

private:
    ControlBlockBase<T>* control_block_;
    friend class SharedPtr<T>;
};

template <typename T>
WeakPtr<T>::WeakPtr() : control_block_(nullptr) {
}

template <typename T>
WeakPtr<T>::WeakPtr(const SharedPtr<T>& other) : control_block_(other.control_block_) {
    if (control_block_) {
        control_block_->WeakIncrement();
    }
}

template <typename T>
WeakPtr<T>::WeakPtr(const WeakPtr& other) : control_block_(other.control_block_) {
    if (control_block_) {
        control_block_->WeakIncrement();
    }
}

template <typename T>
WeakPtr<T>::WeakPtr(WeakPtr&& other) noexcept : control_block_(other.control_block_) {
    other.control_block_ = nullptr;
}

template <typename T>
WeakPtr<T>::~WeakPtr() {
    Reset();
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr& other) {
    if (this == &other)
        return *this;
    Reset();
    control_block_ = other.control_block_;
    if (control_block_) {
        control_block_->WeakIncrement();
    }
    return *this;
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const SharedPtr<T>& other) {
    Reset();
    control_block_ = other.control_block_;
    if (control_block_) {
        control_block_->WeakIncrement();
    }
    return *this;
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(WeakPtr&& other) noexcept {
    if (this == &other)
        return *this;
    Reset();
    control_block_ = other.control_block_;
    other.control_block_ = nullptr;
    return *this;
}

template <typename T>
bool WeakPtr<T>::IsExpired() const {
    return !control_block_ || control_block_->GetStrong() == 0;
}

template <typename T>
SharedPtr<T> WeakPtr<T>::Lock() const {
    if (IsExpired()) {
        return SharedPtr<T>();
    }
    return SharedPtr<T>(*this);
}

template <typename T>
void WeakPtr<T>::Reset() {
    if (control_block_) {
        control_block_->WeakDecrement();
        if (control_block_->GetStrong() == 0 && control_block_->GetWeak() == 0) {
            delete control_block_;
        }
        control_block_ = nullptr;
    }
}

template <typename T>
size_t WeakPtr<T>::UseCount() const {
    return control_block_ ? control_block_->GetStrong() : 0;
}

template <typename T>
SharedPtr<T>::SharedPtr(const WeakPtr<T>& other) : control_block_(other.control_block_) {
    if (control_block_ && control_block_->GetStrong() > 0) {
        control_block_->StrongIncrement();
    } else {
        control_block_ = nullptr;
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(ControlBlockBase<T>* control_block) : control_block_(control_block) {
}

template <typename T>
void DefaultDeleter<T>::operator()(T* ptr) const {
    delete ptr;
}

template <typename T>
void DefaultDeleter<T[]>::operator()(T* ptr) const {
    delete[] ptr;
}

template <typename T, typename... Args>
SharedPtr<T> MakeShared(Args&&... args) {
    ControlBlockWithDeleter<T, DefaultDeleter<T>>* control_block =
        new ControlBlockWithDeleter<T, DefaultDeleter<T>>(new T(std::forward<Args>(args)...),
                                                          DefaultDeleter<T>(), 1, 0);
    return SharedPtr<T>(control_block);
}
