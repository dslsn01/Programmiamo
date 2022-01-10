/* file esercizio13.cpp */

#include <iostream>

using std::cout;
using std::endl;

int square(int n) {
	return n * n;
}

int main()
{
	for (int n = 1; n <= 10; n++) {
		cout << n << " al quadrato = " << square(n) << endl;
	}
}

