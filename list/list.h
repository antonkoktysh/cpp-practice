#pragma once

#include <cstddef>
#include <iterator>
#include <iostream>

class BaseNode {
public:
    BaseNode* prev{nullptr};
    BaseNode* next{nullptr};
};

template <typename T>
class Node : public BaseNode {
public:
    T value;

    Node(const T& val) : value(val) {
    }

    Node(T&& val) : value(std::move(val)) {
    }
};

template <typename T>
class List {
public:
    class Iterator {
    private:
        BaseNode* it_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator() = default;
        Iterator(const Iterator&) = default;
        Iterator(Iterator&& other) = default;
        Iterator& operator=(const Iterator&) = default;
        Iterator& operator=(Iterator&&) noexcept = default;
        Iterator(BaseNode* it) : it_(it) {
        }

        Iterator& operator++() {
            it_ = it_->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator to_return = *this;
            it_ = it_->next;
            return to_return;
        }

        Iterator& operator--() {
            it_ = it_->prev;
            return *this;
        }

        Iterator operator--(int) {
            Iterator to_return = *this;
            it_ = it_->prev;
            return to_return;
        }

        T& operator*() const {
            return static_cast<Node<T>*>(it_)->value;
        }
        T* operator->() const {
            return &static_cast<Node<T>*>(it_)->value;
        }
        BaseNode* Get() const {
            return it_;
        }
        bool operator==(const Iterator& other) const = default;
        bool operator!=(const Iterator& other) const = default;
    };

    List() : head_(new BaseNode) {
        head_->prev = head_;
        head_->next = head_;
    }

    List(const List& other) : head_(new BaseNode) {
        head_->prev = head_;
        head_->next = head_;
        for (auto it = other.head_->prev; it != other.head_; it = it->prev) {
            LinkAfter(head_, new Node<T>(*static_cast<Node<T>*>(it)));
        }
    }

    List(List&& other) noexcept : head_(other.head_), size_(other.size_) {
        other.head_ = new BaseNode;
        other.head_->prev = other.head_;
        other.head_->next = other.head_;
        other.size_ = 0U;
    }

    ~List() {
        auto it = head_->next;
        while (it != head_) {
            Unlink(head_->next);
            it = head_->next;
        }
        // head_->next = nullptr;
        // head_->prev = nullptr;
        size_ = 0U;
        delete head_;
    }

    List& operator=(const List& other) {
        if (&other == this) {
            return *this;
        }
        while (size_ > 0U) {
            PopBack();
        }
        for (auto it = other.head_->next; it != other.head_; it = it->next) {
            PushBack(static_cast<Node<T>*>(it)->value);
        }
        // *this = List(other);
        return *this;
    }

    List& operator=(List&& other) noexcept {
        if (&other == this) {
            return *this;
        }
        this->~List();
        head_ = other.head_;
        size_ = other.size_;
        other.head_ = new BaseNode;
        other.head_->prev = other.head_;
        other.head_->next = other.head_;
        return *this;
    }

    bool IsEmpty() const {
        return size_ == 0U;
    }

    size_t Size() const {
        return size_;
    }

    void PushBack(const T& value) {
        LinkAfter(head_->prev, new Node<T>{value});
    }

    void PushBack(T&& value) {
        LinkAfter(head_->prev, new Node<T>{std::move(value)});
    }

    void PushFront(const T& value) {
        LinkAfter(head_, new Node<T>{value});
    }

    void PushFront(T&& value) {
        LinkAfter(head_, new Node<T>{std::move(value)});
    }

    T& Front() {
        return static_cast<Node<T>*>(head_->next)->value;
    }
    const T& Front() const {
        return static_cast<Node<T>*>(head_->next)->value;
    }
    T& Back() {
        return static_cast<Node<T>*>(head_->prev)->value;
    }
    const T& Back() const {
        return static_cast<Node<T>*>(head_->prev)->value;
    }

    void PopBack() {
        if (size_ == 0U) {
            return;
        }
        Unlink(head_->prev);
    }
    void PopFront() {
        if (size_ == 0U) {
            return;
        }
        Unlink(head_->next);
    }

    void Erase(Iterator it) {
        if (size_ == 0U || it == End()) {
            return;
        }
        Unlink(it.Get());
    }

    Iterator Begin() {
        return Iterator(head_->next);
    }

    Iterator End() {
        return Iterator(head_);
    }

private:
    BaseNode* head_{nullptr};
    size_t size_{0U};

    void Unlink(BaseNode* target) {
        if (head_ == target) {
            return;
        }
        BaseNode* prev = target->prev;
        BaseNode* next = target->next;
        prev->next = next;
        next->prev = prev;
        --size_;
        delete static_cast<Node<T>*>(target);
    }

    void LinkAfter(BaseNode* target, Node<T>* after) {
        BaseNode* temp = target->next;
        target->next = after;
        temp->prev = after;
        after->prev = target;
        after->next = temp;
        ++size_;
    }
};

template <typename T>
typename List<T>::Iterator begin(List<T>& list) {
    return list.Begin();
}

template <typename T>
typename List<T>::Iterator end(List<T>& list) {
    return list.End();
}