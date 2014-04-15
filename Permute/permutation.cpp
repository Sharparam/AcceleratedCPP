#include "permutation.h"

bool compare_permutations(const Permutation &a, const Permutation &b)
{
	return a.right < b.right;
}
