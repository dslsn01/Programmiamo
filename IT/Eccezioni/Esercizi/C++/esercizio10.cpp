/*
file esercizio10.cpp
compilare con: g++ -std=c++11 esercizio10.cpp
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
	double sq = -1;
	while (sq < 0) {
		try 
		{
			cout << "Scrivi un numero: ";

			string s;
			getline(cin, s);
			int n = stoi(s);

			if (n < 0) {
				throw domain_error("Errore di dominio matematico: radice quadrata non definita per i numeri negativi");
			}

			sq = sqrt(n);

			cout << "Radice quadrata di " << n << " = " << sq << endl;
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

