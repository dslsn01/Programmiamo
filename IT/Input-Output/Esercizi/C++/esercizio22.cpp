/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istreambuf_iterator;
using std::equal;

int main()
{
	cout << "Confronto tra file" << endl;

	string filename1;
	cout << "Primo file: ";
	getline(cin, filename1);

	string filename2;
	cout << "Secondo file: ";
	getline(cin, filename2);

	ifstream doc1(filename1, ifstream::ate | ifstream::binary);
	ifstream doc2(filename2, ifstream::ate | ifstream::binary);

	if (doc1 && doc2) {
		bool comp = false;

		if (doc1.tellg() == doc2.tellg()) {
			doc1.seekg(0, ifstream::beg);
			doc2.seekg(0, ifstream::beg);
			istreambuf_iterator<char> compare1(doc1.rdbuf());
			istreambuf_iterator<char> compare2(doc2.rdbuf());

			if (equal(compare1, istreambuf_iterator<char>(), compare2)) {
				comp = true;
			}
			else {
				comp = false;
			}
		}

		if (comp) {
			cout << "I file sono uguali." << endl;
		}
		else {
			cout << "I file sono diversi!" << endl;
		}
	}
	else {
		cout << "Non trovo i file da confrontare!" << endl;
	}
}

