/*
file testNumber.cpp
compilare con: g++ -std=c++11 testNumber.cpp
*/

#include <iostream>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::regex;

int main()
{
	cout << "Digita un numero intero o in virgola mobile: ";

	string s;
	getline(cin, s);

	regex r1("^[0-9]+$");
	regex r2(R"(^[0-9]+\.[0-9]{1,}$)");

	// controlla con due regex se "s" sia un numero intero/decimale

	if (regex_match(s, r1)) {
		cout << s << " è un numero intero." << endl;
	}
	else if (regex_match(s, r2)) {
		cout << s << " è un numero in virgola mobile." << endl;
	}
	else {
		cout << "Attenzione! \"" << s << "\" non è un numero!" << endl;
	}
}

