/* 
file testNumber.cpp
compilare con: g++ -std=c++11 testNumber.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	/* legge un numero da tastiera */

	cout << "Inserisci un intero positivo compreso tra 2 e 10: ";

	string s;
	getline(cin, s);

	if (s.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	/* converte la stringa letta da tastiera in un numero */

	int n = stoi(s);

	/* controlla che il valore inserito non sia negativo o nullo */

	if (!(n > 0) || n == 0) {
		cout << "Il numero inserito dev'essere maggiore di zero!" << endl;
	}
	else
	{
		/* controlla che il valore inserito non sia minore di 2 o maggiore di 10 */

		if (n >= 2 && n <= 10) {
			cout << "Hai digitato " << n << "." << endl;
		}
		else
		{
			cout << "Valore fuori dall'intervallo!" << endl;
		}
	}
}

