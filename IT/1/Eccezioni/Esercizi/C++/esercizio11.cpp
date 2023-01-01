/*
file esercizio11.cpp
compilare con: g++ -std=c++11 esercizio11.cpp
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
	double c = 0;

	while (c == 0) {
		try
		{
			cout << "Scrivi un numero: ";

			string s;
			getline(cin, s);
			int n = stoi(s);

			if (n == 0) {
				throw domain_error("Errore di dominio matematico: radice cubica di zero non definita");
			}

			c = cbrt(n);

			cout << "Radice cubica di " << n << " = " << c << endl;
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

