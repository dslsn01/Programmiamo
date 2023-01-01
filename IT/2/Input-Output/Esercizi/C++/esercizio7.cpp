/*
file esercizio7.cpp
compilare con: g++ -std=c++11 esercizio7.cpp
*/

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main()
{
	cout << "Apri il file: ";

	string filename;
	getline(cin, filename);

	ifstream f(filename);
	string s;

	while (getline(f, s)) {
		cout << s << endl;
	}

	cout << "-> torna alla prima riga." << endl;

	f.clear();
	f.seekg(0, ifstream::beg);

	while (getline(f, s)) {
		cout << s << endl;
	}
}

