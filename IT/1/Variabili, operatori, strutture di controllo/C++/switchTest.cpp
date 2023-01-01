/*
file switchTest.cpp 
compilare con: g++ -std=c++11 switchTest.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << "Inserisci un intero positivo compreso tra 1 e 3: ";
	string s;
	getline(cin, s);

	if (s.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	int n = stoi(s);

	switch (n) {
		case 1:
			cout << "Hai digitato il numero 1." << endl;
			break;

		case 2: 
			cout << "Hai digitato il numero 2." << endl;
			break;

		case 3:
			cout << "Hai digitato il numero 3." << endl;
			break;
			
		default:
			cout << "Numero fuori dell'intervallo!" << endl;
			break;
	}
}

