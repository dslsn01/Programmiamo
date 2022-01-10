/* file esercizio10.cpp */

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::setprecision;

double divide(int a, int b) {
	return b != 0 ? (double) a / b : NAN;
}

int main()
{
	int a = 10;
	int b = 3;
	int c = 0;

	cout << a << " / " << b << " = " << setprecision(4) << divide(a, b) << endl;
	cout << a << " / " << c << " = " << divide(a, c) << endl;
}

