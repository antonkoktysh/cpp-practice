#pragma once

#include "student.h"

#include <vector>
#include <stdexcept>
#include <algorithm>

enum class SortType { kByName, kByDate };

bool ByName(const Student& first, const Student& second);

bool ByDate(const Student& first, const Student& second);

bool ByName(const Student& first, const Student& second) {
    if (first.surname == second.surname) {
        if (first.name == second.name) {
            return ByDate(first, second);
        } else {
            return first.name < second.name;
        }
    } else {
        return first.surname < second.surname;
    }
}

bool ByDate(const Student& first, const Student& second) {
    if (first.year == second.year) {
        if (first.month == second.month) {
            if (first.day == second.day) {
                return ByName(first, second);
            } else {
                return first.day < second.day;
            }
        } else {
            return first.month < second.month;
        }
    } else {
        return first.year < second.year;
    }
}

void SortStudents(std::vector<Student>* students, SortType sort_type) {
    if (sort_type == SortType::kByName) {
        std::sort(students->begin(), students->end(), ByName);
    } else {
        std::sort(students->begin(), students->end(), ByDate);
    }
}
