/*
file esercizio13.cpp
compilare con: g++ -std=c++11 esercizio13.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// si notil'operatore "*" nella doppia veste di operatore prodotto e deriferimento!
void square(int *n) {
	*n = (*n) * (*n);
}

int main()
{
	cout << "Scrivi un numero intero: ";

	string s;
	getline(cin, s);

	if (s.empty() || s.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return -1;
	}

	int n = stoi(s);

	square(&n);

	cout << s << " al quadrato = " << n << endl;
}

