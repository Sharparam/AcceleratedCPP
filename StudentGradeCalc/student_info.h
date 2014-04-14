#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "grade.h"

struct Student_info {
	std::string name;
	double final_grade;
};

bool compare(const Student_info& a, const Student_info& b);
std::istream& read(std::istream& is, Student_info& student);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);
