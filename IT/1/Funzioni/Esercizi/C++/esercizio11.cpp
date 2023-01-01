/* file esercizio11.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

bool isMult(int a, int b) {
	if (a == 0 || b == 0) return false;
	return a < b ? b % a == 0 : a % b == 0;
}

int main() 
{
	int a = 5;
	int b = 10;
	int c = 11;

	cout << b << " è multiplo di " << a << "? " << boolalpha << isMult(a, b) << endl;
	cout << c << " è multiplo di " << a << "? " << boolalpha << isMult(c, a) << endl;
}

