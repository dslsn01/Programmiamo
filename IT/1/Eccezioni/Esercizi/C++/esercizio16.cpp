/*
file esercizio16.cpp
compilare con: g++ -std=c++11 esercizio16.cpp
*/

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::invalid_argument;
using std::runtime_error;
using std::domain_error;

int main()
{
	cout << "Divisione tra numeri interi" << endl;

	try {
		string s;
		cout << "Dividendo: ";
		getline(cin, s);
		int a = stoi(s);

		cout << "Divisore: ";
		getline(cin, s);
		int b = stoi(s);

		if (b == 0) {
			if (a == 0) {
				throw domain_error("Operazione non definita!");
			} else {
				throw runtime_error("Divisione per zero!");
			}
		}

		double result = (double)a / b;

		cout << a << " / " << b << " = " << result << endl;
	}
	catch (invalid_argument &e) {
		cerr << e.what() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}
	catch (domain_error& e) {
		cerr << e.what() << endl;
	}

	cout << "Fine del programma." << endl;
}

