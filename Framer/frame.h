#pragma once

#include <string>
#include <vector>

std::vector<std::string> frame(std::vector<std::string> &lines);
std::string::size_type max_width(const std::vector<std::string> &strings);
std::vector<std::string> vcat(const std::vector<std::string> &top, const std::vector<std::string> &bottom);
std::vector<std::string> hcat(const std::vector<std::string> &left, const std::vector<std::string> &right);
