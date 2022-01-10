/* 
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	int i = 0;
	int x = 0;

	while (i < 10) {
		cout << "Numero corrente: ";
		string s;
		getline(cin, s);

		if (s.find_first_not_of("0123456789") != string::npos) {
			cout << "Numero non valido!" << endl;
			continue;
		}

		int n = stoi(s);

		if (n > x) {
			x = n;
		}

		i++;
	}

	cout << "Il numero più grande è " << x << "." << endl;
}

