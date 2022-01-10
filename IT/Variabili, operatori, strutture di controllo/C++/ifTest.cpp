/* 
file ifTest.cpp
compilare con: g++ -std=c++11 ifTest.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	/* legge da tastiera il numero intero digitato dall'utente */

	cout << "Inserisci un intero: ";
	string s;
	getline(cin, s);

	if (s.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	/* converte la stringa in un numero intero */

	const int n = stoi(s);

	/* controlla se il numero digitato sia pari o dispari */

	if (n % 2 == 0)
	{
		cout << n << " è pari!" << endl;
	}
	else {
		cout << n << " è dispari!" << endl;
	}
}

