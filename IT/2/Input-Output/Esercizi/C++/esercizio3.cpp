/*
file esercizio3.cpp
compilare con: g++ -std=c++11 esercizio3.cpp
*/

#include <iostream>
#include <fstream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::runtime_error;

int main() 
{
	cout << "Apri il file: ";

	string filename;
	getline(cin, filename);

	ifstream file(filename);

	try {
		if (file) {
			cout << "File aperto con successo." << endl;
		}
		else {
			throw runtime_error("Impossibile aprire il file!");
		}
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}
}

