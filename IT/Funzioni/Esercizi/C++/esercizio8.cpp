/* file esercizio8.cpp */

#include <iostream>

using std::cout;
using std::endl;

int add(int a, int b) {
	return a + b;
}

int main()
{
	int a = 5;
	int b = 10;

	cout << a << " + " << b << " = " << add(a, b) << endl;
}

