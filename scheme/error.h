#pragma once

#include <stdexcept>
#include <string>

class SyntaxError : public std::runtime_error {
    using std::runtime_error::runtime_error;
    SyntaxError() : std::runtime_error("Syntax error") {
    }
};

class RuntimeError : public std::runtime_error {
    using std::runtime_error::runtime_error;
    RuntimeError() : std::runtime_error("Syntax error") {
    }
};

class NameError : public std::runtime_error {
public:
    explicit NameError(const std::string& name) : std::runtime_error{"Name not found: " + name} {
    }
};
