/* file esercizio1.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 5;
	int b = 10;

	cout << "a = " << a << ", b = " << b << endl;

	int c = a + b;
	a = a + b;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

