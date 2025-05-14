#pragma once

#include <memory>
#include <string>

class Object : public std::enable_shared_from_this<Object> {
public:
    virtual ~Object() = default;
};

class Number : public Object {
public:
    Number(int value) : value_(value) {
    }

    Number(const Number& other) : value_(other.value_) {
    }

    int GetValue() const {
        return value_;
    }

private:
    int value_;
};

class Symbol : public Object {
public:
    const std::string& GetName() const {
        return name_;
    }
    Symbol(const std::string& name) : name_(name) {
    }
    Symbol(const Symbol& other) : name_(other.name_) {
    }

private:
    std::string name_;
};

// class Dot : public Object {
// };
// class OpenPar : public Object {
// };
// class ClosePar : public Object {
// };
class Cell : public Object {
public:
    std::shared_ptr<Object> GetFirst() const {
        return first_;
    }
    std::shared_ptr<Object> GetSecond() const {
        return second_;
    }
    Cell(const std::shared_ptr<Object>& first, const std::shared_ptr<Object>& second)
        : first_(first), second_(second) {
    }
    Cell() = default;

private:
    std::shared_ptr<Object> first_;
    std::shared_ptr<Object> second_;
};

template <class T>
std::shared_ptr<T> As(const std::shared_ptr<Object>& obj) {
    return std::dynamic_pointer_cast<T>(obj);
}
// https://stackoverflow.com/questions/48971147/what-is-the-use-of-dynamic-pointer-cast-in-c-when-is-it-used-what-are-altern
template <class T>
bool Is(const std::shared_ptr<Object>& obj) {
    return (std::dynamic_pointer_cast<T>(obj) != nullptr);
}
