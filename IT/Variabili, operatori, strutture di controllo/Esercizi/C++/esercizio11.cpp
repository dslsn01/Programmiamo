/* file esercizio11.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	for (int i = 1; i <= 100; i++) {
		if (i % 5 == 0) {
			cout << i << " ";
		}
	}

	cout << endl;
}

