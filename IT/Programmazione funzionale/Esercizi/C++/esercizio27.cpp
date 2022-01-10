/* file esercizio27.cpp */

#include <iostream>

using std::cout;
using std::endl;

void forn(int n) {
	if (n > 0) {
		forn(n-1);
		cout << n <<  " ";
	}
}

int main() {
	forn(10);
	cout << endl;
}

