/* file esercizio4.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 5;
	int b = 10;

	cout << "a = " << a << ", b = " << b << endl;

	int s = a + b;

	cout << a << " + " << b << " = " << s << endl;

	int d = a - b;

	if (d < 0) {
		cout << "Differenza negativa!" << endl;
	}

	cout << a << " - " << b << " = " << d << endl;

	if (d != b - a) {
		cout << "Sottrazione non commutativa. Scambio gli operandi." << endl;
		d = b - a;
		cout << b << " - " << a << " = " << d << endl;
	}

	int p = a * b;

	cout << a << " * " << b << " = " << p << endl;

	double q = (double)a / b;

	cout << a << " / " << b << " = " << q << endl;

	if (q != (double)b / a) {
		cout << "Divisione non commutativa. Scambio gli operandi." << endl;
		q = (double)b / a;
		cout << b << " / " << a << " = " << q << endl;
	}
}

