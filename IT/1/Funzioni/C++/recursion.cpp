/*
file recursion.cpp 
compilare con: g++ -std=c++11 recursion.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

long factorial(int);

int main() 
{
	cout << "Inserisci un numero intero compreso tra zero e 20: ";
	string s;
	getline(cin, s);

	if (s.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	int n = stoi(s);

	if (n > 20) {
		cout << "Numero fuori dell'intervallo!" << endl;
		return 0;
	}

	long fact = factorial(n);

	cout << n << "! = " << fact << endl;
}

long factorial(int n) {
	if (n == 0 || n == 1) return 1;
	else return n * factorial(n - 1);
}

