/* 
file testMap.cpp
compilare con: g++ -std=c++11 testMap.cpp
*/

#include <iostream>
#include <map>

using std::string;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::map;

int main() {
	/* crea una mappa con tre coppie chiave-valore */

	map<string, string> dict;

	dict.insert(make_pair("nome", "John"));
	dict.insert(make_pair("cognome", "Doe"));
	dict.insert(make_pair("anni", "30"));

	for (auto& pair : dict) {
		cout << pair.first << "=" << pair.second << " ";
	}

	cout << endl;

	/* verifica la presenza della chiave "nome" nella mappa, e stampa il valore corrente */

	if (dict.count("nome")) {
		auto it = dict.find("nome");
		string name = it->second;
		cout << "Valore della chiave \"nome\": " << name << endl;

		/* modifica e stampa il valore associato alla chiave "nome" nella mappa */
		it->second = "Steve";
		cout << "Nuovo valore della chiave \"nome\": " << it->second << endl;
	}

	/* aggiunge una nuova coppia chiave-valore alla mappa */

	dict.insert(make_pair("stato civile", "sposato"));

	cout << "Aggiunto stato civile." << endl;
	cout << "Stampo le coppie chiave-valore." << endl;

	for (auto& pair : dict) {
		cout << pair.first << "=" << pair.second << " ";
	}

	cout << endl;

	/* rimuove una coppia chiave-valore dalla mappa */

	dict.erase("stato civile");

	cout << "Stato civile rimosso." << endl;

	for (auto& pair : dict) {
		cout << pair.first << "=" << pair.second << " ";
	}

	cout << endl;
}

