#include "main.h"
#include <cctype>

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

std::vector<std::string> split(const std::string &str)
{
	std::vector<std::string> ret;
	typedef std::string::size_type string_sz;

	string_sz i = 0;

	while (i != str.size())
	{
		while (i != str.size() && isspace(str[i]))
			i++;

		string_sz j = i;

		while (j != str.size() && !isspace(str[j]))
			j++;

		if (i != j)
		{
			ret.push_back(str.substr(i, j - i));
			i = j;
		}
	}

	return ret;
}
