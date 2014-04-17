#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "grade.h"

struct Student_info {
	std::string name;
	double midterm;
	double finals;
	std::vector<double> homework;
	double final_grade;
};

typedef std::vector<Student_info> student_list_t;
typedef student_list_t::size_type student_list_sz;
typedef student_list_t::iterator student_list_i;
typedef student_list_t::const_iterator student_list_ci;

bool compare(const Student_info& a, const Student_info& b);
std::istream& read(std::istream& is, Student_info& student);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);
bool did_all_hw(const Student_info &student);
bool fgrade(const Student_info& s);
student_list_t extract_fails(student_list_t &students);
double optimistic_median(const Student_info &student);
double median_analysis(const student_list_t &students);
double average_analysis(const student_list_t &students);
double optimistic_median_analysis(const student_list_t &students);
void write_analysis(std::ostream &out, const std::string &name, double analysis(const student_list_t&), const student_list_t &a, const student_list_t &b);
