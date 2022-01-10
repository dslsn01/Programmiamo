/*
file esercizio5.cpp
compilare con: g++ -std=c++11 esercizio5.cpp
*/

#include <iostream>
#include <algorithm>

using std::reverse;
using std::string;
using std::cout;
using std::endl;

int main()
{
	string s = "Ciao, mondo!";

	reverse(s.begin(), s.end());

	for (char c : s) {
		cout << c;
	}

	cout << endl;
}

