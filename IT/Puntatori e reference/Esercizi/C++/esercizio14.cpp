/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void cube(int *n) {
	*n = (*n) * (*n) * (*n);
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

	cube(&n);

	cout << s << " al cubo = " << n << endl;
}

