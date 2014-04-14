#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<std::string> wordlist_t;
typedef wordlist_t::size_type wordlist_sz;

std::istream& read_word(std::istream &is, std::string &word)
{
	if (is)
		is >> word;
	return is;
}

int main(int argc, char **argv)
{
	wordlist_t words;

	std::cout << "End input with EOF" << std::endl;

	std::string word;
	while (read_word(std::cin, word))
	{
		if (word == "EOF")
			break;
		words.push_back(word);
	}

	wordlist_sz count = words.size();

	std::sort(words.begin(), words.end());

	std::string curr_word = words[0];
	wordlist_sz curr_count = 1;

	for (wordlist_sz i = 1; i < count; i++)
	{
		std::string next_word = words[i];
		if (next_word != curr_word)
		{
			std::cout << curr_word << ": " << curr_count << std::endl;
			curr_word = next_word;
			curr_count = 0;
		}
		curr_count++;
	}

	std::cout << curr_word << ": " << curr_count << std::endl;

	std::cout << "Number of words: " << count << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}
