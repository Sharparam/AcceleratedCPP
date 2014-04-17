#include "main.h"
#include <cctype>
#include <algorithm>
#include <iterator>

int main(int argc, char *argv[])
{
	std::string input;
	
	while (std::getline(std::cin, input))
	{
		std::vector<std::string> words = split(input);

		for (std::vector<std::string>::const_iterator iter = words.begin(); iter != words.end(); iter++)
			std::cout << *iter << std::endl;
	}
}
