/*
file esercizio23.cpp
compilare con: g++ -std=c++11 esercizio23.cpp
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

		string line;
		while (getline(f, line)) {
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			if (line.find(copy) != -1) {
				found = true;
				break;
			}
		}

		if (found == true) {
			cout << "Parola \"" << s << "\" presente nel file." << endl;
		}
		else {
			cout << "Parola \"" << s << "\" non trovata!" << endl;
		}
	}
	else {
		cout << "Impossibile aprire il file!" << endl;
	}
}

