/* 
file dynMem.cpp
compilare con: g++ -std=c++11 dynMem.cpp
*/

#include <iostream>

using std::string;
using std::stoi;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main() 
{
	string s;
	cout << "Nominativi totali: ";
	getline(cin, s);

	if (s.empty() ||
		s.find_first_not_of("0123456789") != string::npos ||
		stoi(s) == 0) {
		cout << "Digita un intero positivo!" << endl;
		return -1;
	}

	int size = stoi(s);
	int i = 0;

	/* crea un array dinamico, riservando la memoria necessaria per memorizzare N stringhe */

	string *arr = new string[size];

	/* invita l'utente a digitare n stringhe, e le aggiunge via via all'array dinamico */

	while (i < size) {
		cout << "Inserisci un nominativo: ";
		string curr;
		getline(cin, curr);
		arr[i] = curr;
		i++;
	}
	
	cout << "Nominativi dei clienti: " << endl;

	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << endl;
	}

	/* pulisce la memoria cancellando tutti gli elementi dell'array */

	delete [] arr;
}

