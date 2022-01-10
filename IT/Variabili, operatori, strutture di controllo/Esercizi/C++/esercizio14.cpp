/* file esercizio14.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 100;
	cout << "Divisori di " << a << ": ";

	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			cout << i << " ";
		}
	}

	cout << endl;
}

