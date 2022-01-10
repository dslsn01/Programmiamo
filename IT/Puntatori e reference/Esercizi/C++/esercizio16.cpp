/*
file esercizio16.cpp
compilare con: g++ -std=c++11 esercizio16.cpp
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void exp(double b, double ex, double &result) {
	result = pow(b, ex);
}

int main()
{
	cout << "Calcolo delle potenze." << endl;
	cout << "Base: ";

	string s1;
	getline(cin, s1);

	if (s1.empty() || s1.find_first_not_of("0123456789") != string::npos) {
		cout << "Base non valida!" << endl;
		return -1;
	}

	cout << "Esponente: ";

	string s2;
	getline(cin, s2);

	if (s2.empty() || s2.find_first_not_of("0123456789") != string::npos) {
		cout << "Esponente non valido!" << endl;
		return -1;
	}

	int b = stoi(s1);
	int ex = stoi(s2);

	double result = 0;

	exp(b, ex, result);

	cout << "Potenza di " << b << " elevato a " << ex << " = " << result << endl;
}

