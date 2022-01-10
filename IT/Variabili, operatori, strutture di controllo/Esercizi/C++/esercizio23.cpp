/* 
file esercizio23.cpp
compilare con: g++ -std=c++11 esercizio23.cpp
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

	if (s.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	int n = stoi(s);

	int c = n * n * n;

	cout << n << " al cubo = " << c << endl;
}

