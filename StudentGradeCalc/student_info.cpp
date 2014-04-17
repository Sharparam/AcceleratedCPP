#include "stdafx.h"
#include "student_info.h"
#include "grade.h"
#include "median.h"

bool compare(const Student_info& a, const Student_info& b)
{
	return a.name < b.name;
}

std::istream& read(std::istream& is, Student_info& student)
{
	is >> student.name >> student.midterm >> student.finals;

	read_hw(is, student.homework);

	try
	{
		student.final_grade = grade(student);
	}
	catch (std::domain_error)
	{
		student.final_grade = 0;
	}

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

bool did_all_hw(const Student_info &student)
{
	return ((std::find(student.homework.begin(), student.homework.end(), 0)) == student.homework.end());
}

bool fgrade(const Student_info& s)
{
	return s.final_grade < 60;
}

student_list_t extract_fails(student_list_t &students)
{
	student_list_t fail;
	student_list_i iter = students.begin();

	while (iter != students.end())
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			iter++;
	}

	return fail;
}

double optimistic_median(const Student_info &student)
{
	std::vector<double> nonzero;

	std::remove_copy(student.homework.begin(), student.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(student.midterm, student.finals, 0);
	else
		return grade(student.midterm, student.finals, median(nonzero));
}

double median_analysis(const student_list_t &students)
{
	std::vector<double> grades;

	std::transform(students.begin(), students.end(), back_inserter(grades), safe_grade_aux);

	return median(grades);
}

double average_analysis(const student_list_t &students)
{
	std::vector<double> grades;

	std::transform(students.begin(), students.end(), back_inserter(grades), average_grade);

	return median(grades);
}

double optimistic_median_analysis(const student_list_t &students)
{
	std::vector<double> grades;

	std::transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

	return median(grades);
}

void write_analysis(std::ostream &out, const std::string &name, double analysis(const student_list_t&), const student_list_t &a, const student_list_t &b)
{
	out << name << ": median(a) = " << analysis(a) << ", median(b) = " << analysis(b) << std::endl;
}
