/*
file testGroup.cpp
compilare con: g++ -std=c++11 testGroup.cpp
*/

#include <iostream>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
using std::sregex_iterator;

int main()
{
	string s = "Via Roma 40, Milano, MI";
	regex r1(R"(([\w\s]+),\s([\w]+),\s([\w]{2}))");
	smatch match;

	if (regex_search(s, match, r1)) {
		cout << "Stringa completa: " << match.str(0) << endl;
		cout << "Indirizzo: " << match.str(1) << endl;
		cout << "Città: " << match.str(2) << endl;
		cout << "Provincia: " << match.str(3) << endl;
	}

	cout << endl;

	s = "Nome: \"John\", cognome: \"Doe\", età: \"30\", indirizzo: \"ignoto\" segni particolari: \"\"";
	cout << s << endl;

	regex r2(R"((['\"]).*?\1)");

	sregex_iterator it(s.begin(), s.end(), r2);
	sregex_iterator rend;

	while (it != rend) {
		cout << it->str() << endl;
		++it;
	}
}

