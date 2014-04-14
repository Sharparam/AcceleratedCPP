#include <iostream>
#include <iomanip>
#include <math.h>

int get_len(double n)
{
	return (int)std::ceil(std::log10(n)) + ((int)n % 10 == 0);
}

int main(int argc, char **argv)
{
	const double max = 1000.0;
	const double max_pow = max * max;
	int len = get_len(max);
	int len_pow = get_len(max_pow);
	for (int i = 1; i <= max; i++)
		std::cout << std::setw(len) << i << std::setw(len_pow + 1) << i * i << std::endl;

	int foo;
	std::cin >> foo; // Crappy way to wait for input
}
