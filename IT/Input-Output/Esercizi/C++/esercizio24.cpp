/*
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp
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

		int counter = 0;

		string line;
		while (getline(f, line)) {
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			int pos = 0;
			while ((pos = line.find(copy, pos)) != -1) {
				counter++;
				pos++;
			}
		}

		if (counter != 0) {
			cout << "La parola \"" << s << "\" compare " << counter << " volte nel file." << endl;
		}
		else {
			cout << "Parola \"" << s << "\" non trovata!" << endl;
		}
	}
	else {
		cout << "Impossibile aprire il file!" << endl;
	}
}

