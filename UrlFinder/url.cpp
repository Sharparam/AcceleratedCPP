#include "url.h"
#include <algorithm>
#include <ctype.h>

#define URL_CHARS ""

typedef std::string string;
typedef string::const_iterator string_ci;
typedef std::vector<string> string_vec;
typedef string_vec::const_iterator string_vec_ci;

string_vec find_urls(const string &str)
{
	string_vec ret;
	string_ci b = str.begin();
	string_ci e = str.end();

	while (b != e)
	{
		b = url_beg(b, e);

		if (b != e)
		{
			string_ci after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}

	return ret;
}


std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e)
{
	static const string sep = "://";

	string_ci i = b;

	while ((i = std::search(i, e, sep.begin(), sep.end())) != e)
	{
		if (i != b && i + sep.size() != e)
		{
			string_ci beg = i;

			while (beg != b && isalpha(beg[-1]))
				beg--;

			if (beg != i && url_char(i[sep.size()]))
				return beg;
		}

		i += sep.size();
	}
	
	return e;
}


string_ci url_end(string_ci b, string_ci e)
{
	return std::find_if(b, e, not_url_char);
}

bool url_char(char c)
{
	static const string url_chars = "~;/?:@=&$-_.+!*'(),";
	return isalnum(c) || std::find(url_chars.begin(), url_chars.end(), c) != url_chars.end();
}

bool not_url_char(char c)
{
	return !url_char(c);
}
