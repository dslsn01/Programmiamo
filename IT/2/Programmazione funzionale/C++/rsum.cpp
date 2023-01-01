/* file rsum.cpp */

#include <iostream>

using std::cout;
using std::endl;

int rsum(int n) {
	if (n == 0 || n == 1) return n;
	else {
		return n + rsum(n - 1);
	}
}

int main() {
	cout << "Somma dei numeri da 1 a 100 = " << rsum(100) << endl;
}

