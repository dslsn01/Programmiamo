/* file esercizio13.cpp */

#include <iostream>
#include <sstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;

int main()
{
	cout << "Scrivi una frase e leggi le singole parole: ";
	
	string s;
	getline(cin, s);

	if (s.empty()) {
		cout << "Stringa vuota!" << endl;
		return 1;
	}

	istringstream iss(s);
	string word;

	while (getline(iss, word, ' '))
	{
		cout << word << endl;
	}
}

