#pragma once

#include <string>
#include <stdexcept>
#include <unordered_set>
#include <cctype>

int DifferentWordsCount(const std::string& string) {
    std::string current_word;
    std::unordered_set<std::string> map;
    for (size_t i = 0; i < string.size(); ++i) {
        if (isalpha(string[i])) {
            current_word.push_back(tolower(string[i]));
        } else if (!current_word.empty()) {
            map.insert(current_word);
            current_word.clear();
        }
    }
    if (!current_word.empty()) {
        map.insert(current_word);
    }
    return map.size();
}