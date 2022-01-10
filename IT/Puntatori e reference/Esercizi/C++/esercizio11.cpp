/* file esercizio11.cpp */

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

void divide(int a, int b, double *result) {
	*result = b != 0 ? (double) a / b : NAN;
}

int main()
{
	int a = 10;
	int b = 3;
	int c = 0;

	double result = 0;

	divide(a, b, &result);

	cout << a << " / " << b << " = " << result << endl;

	divide(a, c, &result);

	cout << a << " / " << c << " = " << result << endl;
}

