#include "main.h"
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{
	std::vector<std::string> lines
	{
		"The quick brown fox",
		"jumped over the fence"
	};

	permutations_list permutations = get_permutations(lines);

	std::string::size_type max_len = 0;

	for (auto perm : permutations)
		max_len = std::max(max_len, perm.left.size());

	print_perms(permutations, max_len);

	return 0;
}

void print_perms(const permutations_list &perms, std::string::size_type pad)
{
	for (permutations_list::const_iterator iter = perms.begin(); iter != perms.end(); iter++)
		std::cout << iter->left << std::string(pad - iter->left.size() + 1, ' ') << iter->right << std::endl;
}
