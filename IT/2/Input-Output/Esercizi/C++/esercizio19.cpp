/*
file esercizio19.cpp
compilare con: g++ -std=c++11 esercizio19.cpp
*/

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
	cout << "File da copiare: ";

	string filename;
	getline(cin, filename);

	ifstream doc(filename);

	string bakName = filename + ".bak";
	ofstream backup(bakName);

	string s;

	while (getline(doc, s)) {
		backup << s << endl;
	}

	cout << "File \"" << bakName << "\" salvato su disco." << endl;
}

