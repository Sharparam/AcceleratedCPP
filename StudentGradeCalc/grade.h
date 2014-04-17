#pragma once

#include <vector>
#include "student_info.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);
double safe_grade_aux(const Student_info &student);

double average_grade(const Student_info &student);
