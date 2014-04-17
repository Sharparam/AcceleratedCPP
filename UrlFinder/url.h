#include <string>
#include <vector>

std::vector<std::string> find_urls(const std::string &str);
std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e);
std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e);
bool url_char(char c);
bool not_url_char(char c);
