/*
file esercizio23.cpp
compilare con: g++ -std=c++11 esercizio23.cpp
*/

#include <iostream>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::sregex_token_iterator;

int main()
{
	string s = "qui. quo. qua.";

	cout << s << endl;

	regex r("(^[\w]|\.\s[\w])");

	sregex_token_iterator begin(s.begin(), s.end(), r, {-1, 0});
	sregex_token_iterator end;

	string it = "";
	for_each(begin, end, [&](string const& m) {
		string rep = m;
		if (m.size() == 1 || m[0] == '.') {
			int i = m.size()-1;
			rep[i] = toupper(rep[i]);
		}
		it += rep;
	});

	cout << it << endl;
}

