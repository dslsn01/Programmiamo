/*
file esercizio18.cpp
compilare con: g++ -std=c++11 esercizio18.cpp
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

long factorial(int);

int main() 
{
	cout << "Inserisci un numero intero compreso tra zero e 20: ";
	string s;
	getline(cin, s);

	try {
		double d = stod(s);
		if (d < 0 || floor(d) != d) {
			throw domain_error("Errore di dominio matematico: fattoriale definito solo per i numeri naturali!");
		}

		int n = (int)d;

		long fact = factorial(n);

		cout << n << "! = " << fact << endl;
	}
	catch (invalid_argument &e) {
		cerr << e.what() << endl;
	}
	catch (domain_error &e) {
		cerr << e.what() << endl;
	}

	cout << "Fine del programma." << endl;
}

long factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

