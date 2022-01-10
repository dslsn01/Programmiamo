/*
file esercizio15.cpp
compilare con: g++ -std=c++11 esercizio15.cpp
*/

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main()
{
	string filename = "file.txt";
	ifstream doc(filename);

	string s;

	while (getline(doc, s)) {
		cout << s << " ";
	}

	cout << s << endl;
}

