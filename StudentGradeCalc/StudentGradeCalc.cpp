// StudentGradeCalc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	student_list_t students;
	Student_info record;
	std::string::size_type maxlen = 0;

	while (read(std::cin, record))
	{
		maxlen = std::max(maxlen, record.name.size());
		students.push_back(record);
	}

	std::sort(students.begin(), students.end(), compare);

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

	return 0;
}
