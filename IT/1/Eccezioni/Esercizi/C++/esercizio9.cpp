/*
file esercizio9.cpp
compilare con: g++ -std=c++11 esercizio9.cpp -o <nome>
*/

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::invalid_argument;

int main()
{
	int square = 0;

	while (square == 0) {
		cout << "Scrivi un numero: ";
		string s;
		getline(cin, s);

		try
		{
			int n = stoi(s);
			square = n * n;
			cout << n << " al quadrato = " << square << endl;
		}
		catch (invalid_argument &e) {
			cerr << e.what() << endl;
		}
	}

	cout << "Fine del programma." << endl;
}

