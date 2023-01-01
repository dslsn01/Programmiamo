/* 
file esercizio25.cpp
compilare con: g++ -std=c++11 esercizio25.cpp
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

	if (s.find_first_not_of("0123456789.") != string::npos
		|| s.find_first_of(".") == s.size()-1) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	double x = stod(s);

	double xv = x >= 0 ? x : -x;

	cout << "Valore assoluto di " << x << " = " << xv << endl;
}

