/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp
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

	int linecount = count(istreambuf_iterator<char>(doc), istreambuf_iterator<char>(), '\n');

	cout << "Il file \"" << filename << "\" contiene " << linecount << " righe." << endl;
}

