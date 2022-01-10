/* file esercizio9.cpp */

#include <iostream>

using std::cout;
using std::endl;

double add(double a, double b) {
	return a + b;
}

int main()
{
	double a = 2.5;
	double b = 10.5;

	cout << a << " + " << b << " = " << add(a, b) << endl;
}

