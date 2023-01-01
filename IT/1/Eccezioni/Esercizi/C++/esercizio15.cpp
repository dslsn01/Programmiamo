/*
file esercizio15.cpp
compilare con: g++ -std=c++11 esercizio15.cpp
*/

#include <iostream>
#include <cmath>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::invalid_argument;
using std::domain_error;

int main()
{
	cout << "Pari o dispari?" << endl;

	cout << "Scrivi un numero: ";
	string s;
	getline(cin, s);

	try {
		double d = stod(s);

		if (!(d == floor(d))) {
			throw domain_error("Errore di dominio matematico: la distinzione tra \"pari\" o \"dispari\" vale solo per i numeri interi!");
		}

		int n = (int)d;
		if (n % 2 == 0) {
			cout << n << " è pari!" << endl;
		}
		else {
			cout << n << " è dispari!" << endl;
		}
	}
	catch (invalid_argument &e) {
		cerr << e.what() << endl;
	}
	catch (domain_error &e) {
		cerr << e.what() << endl;
	}

	cout << "Fine del programma." << endl;
}

