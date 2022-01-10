/* file esercizio23.cpp */

#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

int mcd(int m, int n);

int main() 
{
	printf("MCD(%d, %d) = %d\n", 24, 36, mcd(24, 36));
	printf("MCD(%d, %d) = %d\n", 42, 56, mcd(42, 56));
	printf("MCD(%d, %d) = %d\n", 54, 72, mcd(54, 72));
}

int mcd(int m, int n) {
	if (n == 0) return 0;
	int r = 0;
	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}

	return m;
}

