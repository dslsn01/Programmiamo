/*
file stringConcat.cpp
compilare con: g++ -std=c++11 stringConcat.cpp
*/

#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::stringstream;

int main()
{
	string hello = "Ciao, ";
	string world = "mondo!";

	/* concatena le due stringhe, usando l'operatore "+" */

	string s1 = hello + world;

	cout << s1 << endl;

	/* ...o la funzione string::append(), che modifica la stringa originale */

	cout << hello.append(world) << endl;

	if (hello == s1) {
		cout << "La stringa iniziale \"" << hello << "\" e quella finale \"" << s1 << "\" sono uguali." << endl;
	}

	/* converte il numero 1 nella stringa '1' */

	int n = 1;
	string s2 = " è un numero positivo.";

	/* concatena le due stringhe, usando gli stream */

	stringstream stream;
	stream << n;

	cout << stream.str() + s2 << endl;

	/* ...o la nuova funzione to_string() */

	cout << to_string(n) +  s2 << endl;
}

