/* file passByValue.cpp */

#include <iostream>

using std::cout;
using std::endl;

int square(int n) {
	n = n * n;
	return n;
}

int main()
{
	int n = 2;

	cout << "Valore di n (prima): " << n << endl;

	// reimposta la variabile originale

	n = square(n);

	cout << "Valore di n (dopo): " << n << endl;
}

