/* file esercizio25.cpp */

#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

int mcd(int m, int n);
int mcm(int m, int n);

int main() 
{
	printf("mcm(%d, %d) = %d\n", 640, 480, mcm(640, 480));
	printf("mcm(%d, %d) = %d\n", 1024, 768, mcd(1024, 768));
	printf("mcm(%d, %d) = %d\n", 4096, 2048, mcd(4096, 2048));
}

int mcd(int m, int n) {
	if (n == 0) return 0;
	int r = m % n;
	if (r == 0) { return n; }
	else {
		return mcd(n, r);
	}
}

int mcm(int m, int n) {
	return (m * n) / mcd(m, n);
}

