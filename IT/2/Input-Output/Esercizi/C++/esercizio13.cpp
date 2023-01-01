/*
file esercizio13.cpp
compilare con: g++ -std=c++11 esercizio13.cpp
*/

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

int main()
{
	cout << "Scrivi una serie di parole. Invia la stringa vuota per uscire." << endl;

	cout << "File su cui scrivere: ";

	string filename;
	getline(cin, filename);
	fstream doc(filename);

	if (doc) {
		cout << "Il file esiste. Le modifiche saranno aggiunte al file esistente." << endl;
		doc.close();
		doc.open(filename, fstream::out | fstream::app);
	}
	else {
		doc.open(filename, fstream::out);
	}

	while (true) {
		cout << "Scrivi una parola: ";

		string s;
		getline(cin, s);

		if (s.empty()) {
			break;
		}

		doc << s << endl;
	}

	cout << "File \"" << filename << "\" salvato su disco." << endl;
}

