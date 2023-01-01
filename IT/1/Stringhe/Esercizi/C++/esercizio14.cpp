/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp
*/

#include <iostream>
#include <sstream>
#include <regex>

using std::wstring;
using std::wcin;
using std::wcout;
using std::endl;
using std::istringstream;
using std::wregex;
using std::wsregex_token_iterator;

int main()
{
	wcout << "Scrivi una frase e leggi le singole parole: ";

	wstring s;
	getline(wcin, s);

	if (s.empty()) {
		wcout << "Stringa vuota!" << endl;
		return 1;
	}

	wregex r(L"[\\s\\.,?!]+");

	wsregex_token_iterator it(s.begin(), s.end(), r, {-1});
	wsregex_token_iterator rend;

	while (it != rend) {
		wcout << *it << endl;
		++it;
	}
}

