/* 
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp
*/

#include <iostream>
#include <cmath>

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

	int ex = 2;

	while (ex <= 10) {
		cout << "Potenza di " << n << " elevato a " << ex << " = " << pow(n, ex) << endl;
		ex++;
	}
}

