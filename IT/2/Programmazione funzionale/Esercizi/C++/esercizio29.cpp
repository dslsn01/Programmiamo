/* file esercizio29.cpp */

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double fsqr(double n, double g) {
	if (fabs(g*g - n) <= 0.0001) return g;
	double mid = (g + n/g)/2;
	return fsqr(n, mid);
}

int main() {
	int nums[] = {2, 5, 7, 9, 16, 32, 64, 81};
	for (int i = 0; i < 8; i++) {
		int n = nums[i];
		cout << "sqrt(" << n << ") = " << fsqr(n, n/2) << endl;
	}
}

