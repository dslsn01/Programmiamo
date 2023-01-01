/* 
file esercizio26.cpp
compilare con: g++ -std=c++11 esercizio26.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	cout << "Scrivi un numero: ";

	string s;
	getline(cin, s);

	if (s.find_first_not_of("0123456789-") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	int n = stoi(s);

	if (n > 0) {
		cout << n << " è positivo." << endl;
	}
	else {
		cout << n << " è uguale o minore di zero." << endl;
	}
}

