/* file exceptionHandling.cpp */

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::cerr;
using std::runtime_error;

int main() 
{
	int n = 5;
	int d = 0;
	int q = 0;

	/* inizio del blocco try ... catch */
	try {
		if (d != 0) {
			q = n / d;
			cout << q << endl;
		}
		else {
			throw runtime_error("Divisione per zero!");
		}
	}
	catch (runtime_error &e) {
		// la clausola catch cattura l'eccezione
		cerr << e.what() << endl;
	}

	cout << "Fine del programma." << endl;
}

