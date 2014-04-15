#include "frame.h"
#include <algorithm>

typedef std::string::size_type string_sz;

typedef std::vector<std::string> string_vec;
typedef string_vec::iterator string_vec_i;
typedef string_vec::const_iterator string_vec_ci;
typedef string_vec::size_type string_vec_sz;

string_vec frame(string_vec &lines)
{
	string_vec ret;
	string_sz width = max_width(lines);
	std::string border = std::string(width + 4, '*');

	ret.push_back(border);

	for (string_vec_ci iter = lines.begin(); iter != lines.end(); iter++)
	{
		string_sz len = iter->size();
		std::string line = "* " + (*iter) + std::string(width - len, ' ') + " *";
		ret.push_back(line);
	}

	ret.push_back(border);
	return ret;
}

string_sz max_width(const string_vec &strings)
{
	string_sz max = 0;

	for (string_vec_ci iter = strings.begin(); iter != strings.end(); iter++)
		max = std::max(max, iter->size());

	return max;
}

string_vec vcat(const string_vec &top, const string_vec &bottom)
{
	string_vec result = top;

	result.insert(result.end(), bottom.begin(), bottom.end());

	return result;
}

string_vec hcat(const string_vec &left, const string_vec &right)
{
	string_vec result;

	string_sz width1 = max_width(left) + 1;

	string_vec_sz i = 0;
	string_vec_sz j = 0;

	while (i != left.size() || j != right.size())
	{
		std::string s;

		if (i != left.size())
			s = left[i++];

		s += std::string(width1 - s.size(), ' ');

		if (j != right.size())
			s += right[j++];

		result.push_back(s);
	}

	return result;
}
