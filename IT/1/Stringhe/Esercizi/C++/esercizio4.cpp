/* file esercizio4.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string s = "Ciao, mondo!";

	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s[i];
	}

	cout << endl;
}

