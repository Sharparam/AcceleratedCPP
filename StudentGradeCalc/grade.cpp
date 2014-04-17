#include "stdafx.h"
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "student_info.h"
#include "average.h"

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
	if (hw.size() == 0)
		throw std::domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.finals, s.homework);
}

double safe_grade_aux(const Student_info &student)
{
	try
	{
		return grade(student);
	}
	catch (std::domain_error)
	{
		return grade(student.midterm, student.finals, 0);
	}
}

double average_grade(const Student_info &student)
{
	return grade(student.midterm, student.finals, average(student.homework));
}
