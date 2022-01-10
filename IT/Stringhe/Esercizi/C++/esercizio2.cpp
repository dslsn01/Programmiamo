/* file esercizio2.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string s = "Ciao, mondo!";

	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
	}

	cout << endl;
}

