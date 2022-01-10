/*
file esercizio13.cpp
compilare con: g++ -std=c++11 esercizio13.cpp
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
	double l = -1;

	while (l < 0) {
		cout << "Scrivi un numero: ";
		string s;
		getline(cin, s);

		try
		{
			int n = stoi(s);

			if (n <= 0) {
				throw domain_error("Errore di dominio matematico: logaritmo non definito per n <= 0");
			}

			l = log(n);

			cout << "Logaritmo di " << n << " = " << l << endl;
		}
		catch (invalid_argument &e) {
			cerr << e.what() << endl;
		}
		catch (domain_error &e) {
			cerr << e.what() << endl;
		}
	}

	cout << "Fine del programma." << endl;
}

