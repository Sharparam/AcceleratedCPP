#include "split.h"
#include <algorithm>

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !space(c);
}

std::vector<std::string> split(const std::string &str)
{
	typedef std::string::const_iterator string_ci;
	std::vector<std::string> ret;

	string_ci i = str.begin();

	while (i != str.end())
	{
		i = std::find_if(i, str.end(), not_space);

		string_ci j = std::find_if(i, str.end(), space);

		ret.push_back(std::string(i, j));

		i = j;
	}

	return ret;
}
