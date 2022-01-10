/*
file esercizio17.cpp
compilare con: g++ -std=c++11 esercizio17.cpp
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::count;
using std::istreambuf_iterator;

int main()
{
	string filename = "file.txt";
	ifstream doc(filename);

	int j = count(istreambuf_iterator<char>(doc), istreambuf_iterator<char>(), '\n');

	doc.clear();
	doc.seekg(0, ifstream::beg);

	string s;

	for (int i = 0; i < (j - 3); i++) {
		getline(doc, s);
	}

	while (getline(doc, s)) {
		cout << s << endl;
	}
}

