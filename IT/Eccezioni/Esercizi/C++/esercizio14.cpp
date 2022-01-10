/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp
*/

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::invalid_argument;

int main()
{
	cout << "Scrivi una parola o numero: ";
	string s;
	getline(cin, s);

	try {
		size_t last;
		int n = stoi(s, &last);

		if (last < s.size()) {
			throw invalid_argument("stoi");
		}

		cout << s << " è un numero intero." << endl;
	}
	catch (invalid_argument& e) {
		cerr << e.what() << endl;
		try {
			double d = stod(s);
			cout << s << " è un numero in virgola mobile." << endl;
		}
		catch (invalid_argument& e) {
			cerr << e.what() << endl;
			cout << "\"" << s << "\" non può essere convertito in un numero." << endl;
		}
	}
}

