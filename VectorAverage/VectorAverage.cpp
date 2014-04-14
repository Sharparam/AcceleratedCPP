// VectorAverage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

std::istream& read_number(std::istream &is, double &num)
{
	if (is)
		is >> num;
	return is;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<double> numbers;
	std::vector<double>::size_type count;

	double num;
	while (read_number(std::cin, num))
		numbers.push_back(num);

	count = numbers.size();

	double sum = 0.0;

	for (std::vector<double>::size_type i = 0; i < count; i++)
		sum += numbers[i];

	std::cout << "Count: " << count << ", sum: " << sum << ", average: " << sum / count << std::endl;

	std::cin.clear();
	std::cin.ignore();
	std::cin.get();

	return 0;
}

