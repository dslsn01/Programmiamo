/* 
file testList.cpp 
compilare con: g++ -std=c++11 testList.cpp
*/

#include <iostream>
#include <list>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::list;

int main()
{
	/* dichiara una lista linkata di stringhe */

	list<string> li;

	li.push_back("tigre");
	li.push_back("giraffa");
	li.push_back("elefante");

	/* crea un iteratore per muoversi nella lista */

	list<string>::iterator it;

	/* utilizza l'iteratore per stampare gli elementi della lista */

	for (it = li.begin(); it != li.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;

	/* verifica la presenza dell'"elefante" nella lista, se presente stampa la sua posizione */

	it = find(li.begin(), li.end(), "elefante");

	if (it != li.end()) {
		int index = distance(li.begin(), it);
		cout << "Nella lista c'è un elefante nella posizione " << index << endl;
	}

	/* modifica il secondo elemento in lista da "giraffa" a "cane"" */

	cout << "Sostituisco la giraffa con un cane." << endl;

	it = find(li.begin(), li.end(), "giraffa");
	if (it != li.end()) {
		(*it) = "cane";
	}

	for (string& animal : li) {
		cout << animal << " ";
	}

	cout << endl;

	/* possiamo aggiungere e togliere elementi da una lista linkata in qualsiasi momento */

	cout << "Aggiungo una balenottera azzurra." << endl;
	it = li.begin();
	advance(it, 2);
	//it = find(li.begin(), li.end(), "cane");
	li.insert(it, "balenottera");

	for (string& animal : li) {
		cout << animal << " ";
	}

	cout << endl << "La lista linkata contiene " << li.size() << " elementi." << endl;

	/* rimuove un elemento dalla lista linkata */

	cout << "Rimuovo il cane." << endl;

	it = find(li.begin(), li.end(), "cane");
	li.erase(it);

	for (string& animal : li) {
		cout << animal << " ";
	}

	cout << endl << "La lista linkata contiene " << li.size() << " elementi." << endl;
}

