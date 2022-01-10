/*
file esercizio20.cpp
compilare con: g++ -std=c++11 esercizio20.cpp
*/

#include <iostream>
#include <regex>

using std::string;
using std::cout;
using std::endl;
using std::regex;
using std::smatch;
using std::regex_replace;
using std::sregex_token_iterator;

int main()
{
	// formato SI
	string si = "1 234 567.89";

	// formato USA
	regex r("[\\s]");
	string us = regex_replace(si, r, ",");

	// formato italiano
	regex r2("[\\s\\.]");

	sregex_token_iterator begin(si.begin(), si.end(), r2, {-1, 0});
	sregex_token_iterator end;

	string it = "";
	for_each(begin, end, [&](string const& m) {
		if (iswdigit(m[0])) it += m;
		else {
			string rep = (m == " ") ? "." : ",";
			it += rep;
		}
	});

	cout << "Stile SI: " << si << endl;
	cout << "Stile US: " << us << endl;
	cout << "Stile IT: " << it << endl;
}

