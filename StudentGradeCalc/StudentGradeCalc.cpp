// StudentGradeCalc.cpp : Defines the entry point for the console application.
//

#include "StudentGradeCalc.h"

int _tmain(int argc, _TCHAR* argv[])
{
	student_list_t students;
	Student_info record;
	std::string::size_type maxlen = 0;

	student_list_t did;
	student_list_t didnt;

	while (read(std::cin, record))
	{
		maxlen = std::max(maxlen, record.name.size());
		if (did_all_hw(record))
			did.push_back(record);
		else
			didnt.push_back(record);
		//students.push_back(record);
	}

	if (did.empty())
		std::cout << "No student did all the homework";

	if (didnt.empty())
		std::cout << "Every student did all the homework";

	write_analysis(std::cout, "median", median_analysis, did, didnt);
	write_analysis(std::cout, "average", average_analysis, did, didnt);
	write_analysis(std::cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

	//std::sort(students.begin(), students.end(), compare);
	//print_students(students, maxlen);

	return 0;
}

void print_students(const std::vector<Student_info> &students, std::string::size_type maxlen)
{
	for (student_list_ci iter = students.begin(); iter != students.end(); iter++)
	{
		std::cout << iter->name << std::string(maxlen + 1 - iter->name.size(), ' ');

		try
		{
			double final_grade = iter->final_grade;
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade << std::setprecision(prec);
		}
		catch (std::domain_error e)
		{
			std::cout << e.what();
		}

		std::cout << std::endl;
	}
}
