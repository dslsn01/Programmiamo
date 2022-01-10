/*
file esercizio12.cpp
compilare con: g++ -std=c++11 esercizio12.cpp
*/

#include <iostream>
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
	double r = 0;

	while (r == 0) {
		cout << "Scrivi un numero: ";
		string s;
		getline(cin, s);

		try
		{
			int n = stoi(s);

			if (n == 0) {
				throw domain_error("Errore di dominio matematico: reciproco di zero non definito");
			}

			r = (double)1/n;

			cout << "Reciproco di " << n << " = " << r << endl;
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

