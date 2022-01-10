/*
file esercizio8.cpp
compilare con: g++ -std=c++11 esercizio8.cpp
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
	try {
		cout << "Scrivi un numero: ";

		string s;
		getline(cin, s);
		int n = stoi(s);

		cout << n << " al quadrato = " << n * n << endl;
	}
	catch (invalid_argument &e) {
		cerr << e.what() << endl;
	}

	cout << "Fine del programma." << endl;
}

