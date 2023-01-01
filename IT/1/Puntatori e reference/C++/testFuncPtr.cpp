/*
file testFuncPtr.cpp
compilare con: g++ -std=c++11 testFuncPtr.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void isEven(int n)
{
	cout << n << " è pari!" << endl;
}

void isOdd(int n)
{
	cout << n << " è dispari!" << endl;
}

int main() 
{
	/* dichiara un puntatore a funzione */

	void (*function)(int);

	cout << "Inserisci un numero intero compreso tra 2 e 10: ";

	/* memorizza il numero digitato dall'utente nella variabile locale */

	string s;
	getline(cin, s);

	if (s.empty() || s.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	int n = stoi(s);

	/* a secondo che il numero immesso dall'utente sia pari o dispari, inizializza il puntatore con la funzione adatta */

	if (2 <= n && n <= 10) {
		function = n % 2 == 0 ? isEven : isOdd;

		/* invoca la funzione corretta, passandogli il parametro attraverso il puntatore */

		function(n);
	}
	else {
		cout << "Numero fuori intervallo!" << endl << "Devi inserire un intero compreso tra due e 10." << endl;
	}
}

