#include "main.h"

int main(int argc, char *argv[])
{
	std::vector<std::string> input;
	input.push_back("hello world");
	input.push_back("foo");
	input.push_back("bar");
	input.push_back("baz");
	input.push_back("foo bar baz");

	std::vector<std::string> f = frame(input);

	print_vec(f);

	std::vector<std::string> input2;
	input2.push_back("foo bar baz");
	input2.push_back("hello world");

	input2 = frame(input2);

	std::vector<std::string> v = vcat(f, input2);

	print_vec(v);

	std::vector<std::string> h = hcat(input2, f);

	print_vec(h);
}

void print_vec(const std::vector<std::string> &vec)
{
	for (std::vector<std::string>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << *iter << std::endl;
}
