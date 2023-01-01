/* 
file testArray1.cpp
compilare con: g++ -std=c++11 testArray1.cpp
*/

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::find;
using std::begin;
using std::end;
using std::distance;

int main()
{
	/* dichiara un array di stringhe */

	string arr[] = {"tigre", "giraffa", "elefante"};

	/* stampa il contenuto dell'array con un ciclo for */

	for (int i = 0; i < sizeof(arr) / sizeof(string); i++) {
		cout << i << ") " << arr[i] << endl;
	}

	/* verifica la presenza dell'"elefante" nella lista */

	auto addr = find(begin(arr), end(arr), "elefante");

	/* se l'elefante cercato è nell'array, recupera il suo indice */

	if (addr != end(arr)) {
		int index = distance(arr, addr);
		cout << "Nella lista c'è un elefante alla posizione " << index << "." << endl;
	}

	/* modifica il secondo elemento in lista da "giraffa" a "cane" */

	cout << "Sostituisco la giraffa con un cane." << endl;
	arr[1] = "cane";

	/* itera attraverso la lista con un ciclo foreach */

	for (string& e : arr) {
		cout << e << endl;
	}
}

