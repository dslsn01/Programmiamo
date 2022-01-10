/*
file esercizio2.cpp
compilare con: g++ -std=c++11 esercizio2.cpp
*/

#include <iostream>

using std::cout;
using std::endl;

class Spaceman {
};

int main()
{
	/* creazione "statica" di un oggetto */

	Spaceman neil;

	/* non è (ancora) possibile stampare a video un oggetto di tipo personalizzato */

	// cout << neil << endl;

	/* creazione "dinamica" di un oggetto */

	Spaceman *buzz = nullptr;
	buzz = new Spaceman();

	/* cosa stampa? */
	cout << buzz << endl;

	delete buzz;
}

