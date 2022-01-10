/*
file esercizio12.cpp
compilare con: g++ -std=c++11 esercizio12.cpp
*/

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;

int main()
{
	cout << "Scrivi una serie di parole. Invia la stringa vuota per uscire." << endl;

	string filename = "file.txt";
	ofstream doc(filename);

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

