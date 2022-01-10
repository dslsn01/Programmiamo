/* file receptionist.cpp */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "Benvenuto nel nostro Hotel!" << endl;

	cout << "Nome: ";
	string n;
	getline(cin, n);

	cout << "Cognome: ";

	string s;
	getline(cin, s);

	cout << "Benvenuto, " << n << " " << s << "!" << endl;
}

