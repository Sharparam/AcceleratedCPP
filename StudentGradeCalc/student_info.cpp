#include "stdafx.h"
#include "student_info.h"
#include "grade.h"

bool compare(const Student_info& a, const Student_info& b)
{
	return a.name < b.name;
}

std::istream& read(std::istream& is, Student_info& student)
{
	double mt;
	double f;
	is >> student.name >> mt >> f;

	std::vector<double> hw;
	read_hw(is, hw);
	student.final_grade = grade(mt, f, hw);
	return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
	if (in) {
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}

	return in;
}
