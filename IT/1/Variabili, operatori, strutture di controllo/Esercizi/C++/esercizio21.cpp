/* file esercizio21.cpp */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	cout << "Scrivi una parola: ";
	string w;
	getline(cin, w);

	string str = "Hai scritto: " + w;
	cout << str << endl;
}

