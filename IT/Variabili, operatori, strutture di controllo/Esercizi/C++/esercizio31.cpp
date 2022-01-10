/* 
file esercizio31.cpp
compilare con: g++ -std=c++11 esercizio31.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	cout << "Quanti numeri vuoi inserire? ";

	string l;
	getline(cin, l);

	if (l.find_first_not_of("0123456789") != string::npos) {
		cout << "Numero non valido!" << endl;
		return 0;
	}

	int limit = stoi(l);

	int i = 0;
	int tot = 0;

	while (i < limit) {
		cout << "Numero corrente: ";
		string s;
		getline(cin, s);

		if (s.find_first_not_of("0123456789") != string::npos) {
			cout << "Numero non valido!" << endl;
			continue;
		}

		int n = stoi(s);

		tot += n;

		i++;
	}

	cout << "La media di tutti i numeri è " << (double)tot / limit << "." << endl;
}

