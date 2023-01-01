/* file esercizio10.cpp */

#include <iostream>

using std::cout;
using std::endl;

void add(double a, double b, double* result) {
	*result = a + b;
}

int main()
{
	double a = 2.5;
	double b = 10.5;

	double result = 0;

	add(a, b, &result);

	cout << a << " + " << b << " = " << result << endl;
}

