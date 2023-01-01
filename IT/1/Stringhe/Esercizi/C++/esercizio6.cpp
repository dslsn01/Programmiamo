/*
file esercizio6.cpp
compilare con: g++ -std=c++11 esercizio6.cpp
*/

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::stoi;

int main()
{
	string s = "12345";

	int n = stoi(s);

	if (n % 2 == 0) {
		cout << "Il numero " << s << " è pari." << endl;
	}
	else {
		cout << "Il numero " << s << " è dispari." << endl;
	}
}

