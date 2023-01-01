/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp
*/

#include <iostream>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::sregex_iterator;

int main()
{
	string s = "Nome: \"John\", cognome: \"Doe\", età: 32, indirizzo: \"ignoto\" numero di telefono: 333-1234567\n";
	s += "Nome: \"Paula\", cognome: \"Poe\", età: 30, numero di telefono: 320/1200100\n";
	s += "Nome: \"Joe\", cognome: \"Bloggs\", età: 35, numero di telefono: 02-987654\n";
	s += "Nome: \"Jane\", cognome: \"Doe\", indirizzo: \"?\" numero di telefono: 06/12345001";

	cout << s << endl;

	cout << "Numeri di telefono: " << endl;

	regex r("[\\d]{2,3}[-/]{1}[\\d]{5,8}");

	sregex_iterator it(s.begin(), s.end(), r);
	sregex_iterator rend;

	while (it != rend) {
		cout << it->str() << endl;
		++it;
	}
}

