#include "permute.h"
#include <algorithm>

#include <iostream>

using std::string;

typedef string::size_type string_sz;
typedef std::vector<string> string_vec;
typedef string_vec::iterator string_vec_i;
typedef string_vec::const_iterator string_vec_ci;
typedef string_vec::size_type string_vec_sz;

permutations_list get_permutations(const string_vec &lines)
{
	permutations_list result;
	rotations_list rotations = get_rotations(lines);

	// Woo C++11!
	for (auto rotation : rotations)
	{
		Permutation permutation;
		if (rotation.beginning == 0)
			permutation.right = rotation.line.substr(rotation.beginning);
		else
		{
			permutation.left = rotation.line.substr(rotation.beginning);
			permutation.right = rotation.line.substr(0, rotation.beginning);
		}
		result.push_back(permutation);
	}

	std::sort(result.begin(), result.end(), compare_permutations);

	return result;
}

rotations_list get_rotations(const string &input)
{
	rotations_list result;
	Rotation rotation;

	rotation.line = input;
	rotation.beginning = 0;

	result.push_back(rotation);

	string_sz size = input.size();

	for (string_sz i = 0; i != size; i++)
	{
		while (i != size && !isspace(input[i]))
			i++;

		if (i == size)
			break;

		// char at index i is a whitespace char
		string left = input.substr(0, i);
		string right = input.substr(i + 1, size - i - 1);

		rotation.line = right + " " + left;
		rotation.beginning = right.size() + 1;

		result.push_back(rotation);
	}

	return result;
}

rotations_list get_rotations(const std::vector<string> &lines)
{
	rotations_list result;

	// Woo C++11
	for (auto line : lines)
	{
		rotations_list rotations = get_rotations(line);
		result.insert(result.end(), rotations.begin(), rotations.end());
	}

	return result;
}
