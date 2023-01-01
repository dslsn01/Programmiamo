/* file esercizio12.cpp */

#include <iostream>

using std::cout;
using std::endl;

int isum(int n) {
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += i;
	}

	return tot;
}

int main()
{
	cout << "Somma dei numeri da 1 a 100 = " << isum(100) << endl;
}

