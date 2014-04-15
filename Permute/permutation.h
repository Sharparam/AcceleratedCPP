#pragma once

#include <string>

struct Permutation
{
	std::string left;
	std::string right;
};

bool compare_permutations(const Permutation &a, const Permutation &b);
