/*
file esercizio11.cpp
compilare con: g++ -std=c++11 esercizio11.cpp
*/

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;

int main()
{
	cout << "Scrivi una parola o una frase: ";

	string s;
	getline(cin, s);

	string filename = "file.txt";
	ofstream doc(filename);

	doc << s << endl;

	cout << "File \"" << filename << "\" salvato su disco." << endl;
}

