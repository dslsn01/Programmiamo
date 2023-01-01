/* file esercizio14.cpp */

#include <iostream>

using std::cout;
using std::endl;

int cube(int n) {
	return n * n * n;
}

int main()
{
	for (int n = 1; n <= 10; n++) {
		cout << n << " al cubo = " << cube(n) << endl;
	}
}

