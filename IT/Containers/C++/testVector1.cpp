/* 
file testVector1.cpp 
compilare con: g++ -std=c++11 testVector1.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
// using std::find;
// using std::distance;
// using std::advance;

int main()
{
	/* dichiara un vettore di stringhe */

	vector<string> vect;

	vect.push_back("tigre");
	vect.push_back("giraffa");
	vect.push_back("elefante");

	/* crea un iteratore per muoversi nel vettore */

	vector<string>::iterator it;

	/* utilizza l'iteratore per stampare gli elementi del vettore */

	for (it = vect.begin(); it != vect.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;

	/* verifica la presenza dell'"elefante" nella lista, se presente stampa la sua posizione */

	it = find(vect.begin(), vect.end(), "elefante");

	if (it != vect.end()) {
		int index = distance(vect.begin(), it);
		cout << "Nella lista c'è un elefante nella posizione " << index << endl;
	}

	/* modifica il secondo elemento in lista da "giraffa" a "cane"" */

	cout << "Sostituisco la giraffa con un cane." << endl;

	vect[1] = "cane";

	for (string& animal : vect) {
		cout << animal << " ";
	}

	cout << endl;

	/* possiamo aggiungere e togliere elementi da un vettore in qualsiasi momento */

	cout << "Aggiungo una balenottera azzurra." << endl;
	it = vect.begin();
	advance(it, 2);
	vect.insert(it, "balenottera");

	for (string& animal : vect) {
		cout << animal << " ";
	}

	cout << endl << "Il vettore contiene " << vect.size() << " elementi." << endl;

	/* rimuove un elemento dal vettore */

	cout << "Rimuovo il cane." << endl;

	it = find(vect.begin(), vect.end(), "cane");
	vect.erase(it);

	for (string& animal : vect) {
		cout << animal << " ";
	}

	cout << endl << "Il vettore contiene " << vect.size() << " elementi." << endl;
}

