/*
file esercizio4.cpp
compilare con: g++ -std=c++11 esercizio4.cpp
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

	while (getline(f, s))
	{
		cout << s << endl;
	}
}

