/* file esercizio10.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int i = 1;

	while (i <= 100) {
		if (i % 2 == 0) {
			cout << i << " ";
		}
		i++;
	}

	cout << endl;
}

