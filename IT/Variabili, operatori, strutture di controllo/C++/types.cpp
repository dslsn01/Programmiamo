/* 
file types.cpp
compilare con: g++ -std=c++11 types.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	cout << "Quanti anni hai? ";
	string s;
	getline(cin, s);

	/* controlla che sia stato digitato un numero */

	if (s.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	/* converte gli anni da stringa a numero intero con stoi() */
	int age = stoi(s);

	if (age >= 18) {
		cout << "Puoi prendere la patente." << endl;
	}
	else {
		cout << "Non puoi ancora prendere la patente!" << endl;
	}
}

