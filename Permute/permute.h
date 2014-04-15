#pragma once

#include <vector>
#include <string>

#include "permutation.h"
#include "rotation.h"

typedef std::vector<Permutation> permutations_list;
typedef std::vector<Rotation> rotations_list;

permutations_list get_permutations(const std::vector<std::string> &lines);
rotations_list get_rotations(const std::string &input);
rotations_list get_rotations(const std::vector<std::string> &lines);
