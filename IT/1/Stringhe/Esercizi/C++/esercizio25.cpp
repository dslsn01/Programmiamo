/*
file esercizio.cpp
compilare con: g++ -std=c++11 esercizio.cpp
*/

#include <iostream>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;

int main()
{
	string cod;
	regex r("^[A-Z]{6}[\\d]{2}[ABCDEHLMPRST]{1}(?:0[1-9]|[1-6][\\d]|7[01])[A-Z0-9]{4}[A-Z]{1}$");

	while (cod.empty()) {
		cout << "Digita il tuo codice fiscale: ";
		string s;
		getline(cin, s);

		if (regex_match(s, r)) {
			cod = s;
			cout << "Codice fiscale corretto." << endl;
		}
		else {
			cout << "Codice fiscale non valido!" << endl;
		}
	}
}

