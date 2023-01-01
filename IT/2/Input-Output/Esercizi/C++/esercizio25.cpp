/*
file esercizio25.cpp
compilare con: g++ -std=c++11 esercizio25.cpp
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::transform;

int main()
{
	cout << "Apri il file: ";

	string filename;
	getline(cin, filename);

	ifstream f(filename);

	if (f) {
		cout << "Parola da cercare: ";

		string s;
		getline(cin, s);

		string copy = s;
		transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

		bool found = false;
		int i = 1;

		string line;
		while (getline(f, line)) {
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			if (line.find(copy) != -1) {
				if (!found) found = true;
				cout << "La parola \"" << s << "\" compare alla riga " << i << "." << endl;
			}
			i++;
		}

		if (!found) {
			cout << "Parola \"" << s << "\" non trovata!" << endl;
		}
	}
	else {
		cout << "Impossibile aprire il file!" << endl;
	}
}

