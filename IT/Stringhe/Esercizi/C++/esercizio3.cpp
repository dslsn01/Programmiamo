/* file esercizio3.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string s = "Ciao, mondo!";
	int sz = s.size();

	for (int i = 0; i < sz; i++) {
		cout << "(" << i << ") = '" << s[i] << "'";
		// aggiungo la virgola fino al penultimo carattere
		if (i < sz-1) cout << ", ";
	}

	cout << endl;
}

