/* file esercizio19.cpp */

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 1 || n == 3) return true;

	double sr = sqrt(n);
	for (int i = 2; i <= (int)sr; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main() 
{
	for (int n = 2; n <= 100; n++) {
		if (isPrime(n)) cout << n << " ";
	}

	cout << endl;
}

