#pragma once

#include "student.h"
#include "date.h"

#include <stdexcept>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

bool Comp1(std::tuple<StudentName, Date, int, std::vector<std::string>> a,
           std::tuple<StudentName, Date, int, std::vector<std::string>> b) {
    if (std::get<2>(a) != std::get<2>(b)) {
        return std::get<2>(a) > std::get<2>(b);
    }
    if (std::get<1>(a).year != std::get<1>(b).year) {
        return std::get<1>(a).year < std::get<1>(b).year;
    }
    if (std::get<1>(a).month != std::get<1>(b).month) {
        return std::get<1>(a).month < std::get<1>(b).month;
    }
    if (std::get<1>(a).day != std::get<1>(b).day) {
        return std::get<1>(a).day < std::get<1>(b).day;
    }
    if (std::get<0>(a).surname != std::get<0>(b).surname) {
        return std::get<0>(a).surname < std::get<0>(b).surname;
    }
    return std::get<0>(a).name < std::get<0>(b).name;
}

bool Comp2(StudentName a, StudentName b) {
    if (a.surname != b.surname) {
        return a.surname < b.surname;
    }
    return a.name < b.name;
}

std::map<std::string, std::vector<StudentName>> GetStudents(
    const std::vector<std::pair<std::string, int>>& universities_info,
    const std::vector<std::tuple<StudentName, Date, int, std::vector<std::string>>>&
        students_info) {
    std::vector<std::tuple<StudentName, Date, int, std::vector<std::string>>> student_info_copy =
        students_info;
    std::sort(student_info_copy.begin(), student_info_copy.end(), Comp1);
    std::map<std::string, int> universities;
    std::map<std::string, std::vector<StudentName>> result;
    for (auto el : universities_info) {
        universities.insert({el.first, el.second});
        result.insert({el.first, std::vector<StudentName>(0)});
    }
    for (auto& el : student_info_copy) {
        auto student = std::get<StudentName>(el);
        for (auto& uni : std::get<3>(el)) {
            if (universities[uni] > 0) {
                result[uni].push_back(student);
                --universities[uni];
                break;
            }
        }
    }
    for (auto& pair : result) {
        std::sort(pair.second.begin(), pair.second.end(), Comp2);
    }
    return result;
}