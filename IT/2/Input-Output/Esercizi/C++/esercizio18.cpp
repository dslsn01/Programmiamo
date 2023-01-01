/*
file esercizio18.cpp
compilare con: g++ -std=c++11 esercizio18.cpp
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios_base;
using std::istreambuf_iterator;
using std::count;

int main()
{
	cout << "Apri il file: ";
	string filename;
	getline(cin, filename);

	ifstream doc(filename);

	int linecount = count(istreambuf_iterator<char>(doc), istreambuf_iterator<char>(), '\n');

	doc.clear();
	doc.seekg(0, ifstream::beg);

	string s;
	if (linecount <= 10) {
		while (getline(doc, s)) {
			cout << s << endl;
		}
	}
	else {
		for (int i = 0; i < (linecount - 10); i++) {
			getline(doc, s);
		}

		while (getline(doc, s)) {
			cout << s << endl;
		}
	}
}

