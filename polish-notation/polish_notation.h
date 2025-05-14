#pragma once

#include <string>
#include <stdexcept>
#include <vector>
#include <stack>

std::vector<std::string> Split(const std::string& string, const std::string& delimiter = " ") {
    std::vector<std::string> result;
    if (string.empty()) {
        return result;
    }
    size_t i = 0;
    while (string.find(delimiter, i) != std::string::npos) {
        result.push_back(string.substr(i, string.find(delimiter, i) - i));
        i = string.find(delimiter, i) + delimiter.size();
    }
    result.push_back(string.substr(i, string.size() - i + 1));
    return result;
}

int EvaluateExpression(const std::string& expression) {
    std::vector<std::string> exp = Split(expression);
    std::stack<int> stack_machine;
    for (auto el : exp) {
        if (el == "+" || el == "-" || el == "*") {
            int first_el = stack_machine.top();
            stack_machine.pop();
            int second_el = stack_machine.top();
            stack_machine.pop();
            if (el == "+") {
                stack_machine.push(first_el + second_el);
            }
            if (el == "-") {
                stack_machine.push(second_el - first_el);
            }
            if (el == "*") {
                stack_machine.push(first_el * second_el);
            }
        } else {
            stack_machine.push(std::stoi(el));
        }
    }
    return stack_machine.top();
}
