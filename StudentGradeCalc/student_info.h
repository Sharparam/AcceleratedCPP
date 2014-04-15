#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "grade.h"

struct Student_info {
	std::string name;
	double final_grade;
};

typedef std::vector<Student_info> student_list_t;
typedef student_list_t::size_type student_list_sz;
typedef student_list_t::iterator student_list_i;
typedef student_list_t::const_iterator student_list_ci;

bool compare(const Student_info& a, const Student_info& b);
std::istream& read(std::istream& is, Student_info& student);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);
bool fgrade(const Student_info& s);
student_list_t extract_fails(student_list_t &students);
