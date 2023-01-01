/* file esercizio6.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

bool even(int n) {
	return n % 2 == 0 ? true : false;
}

int main() 
{
	int a = 2;
	int b = 3;

	cout << a << " è pari? " << boolalpha << even(a) << endl;
	cout << b << " è pari? " << boolalpha << even(b) << endl;
}

