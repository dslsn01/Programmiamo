/*
file esercizio16.cpp
compilare con: g++ -std=c++11 esercizio16.cpp
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

	for (int i = 0; i < 3; i++)	{
		getline(doc, s);
		cout << s << endl;
	}
}

