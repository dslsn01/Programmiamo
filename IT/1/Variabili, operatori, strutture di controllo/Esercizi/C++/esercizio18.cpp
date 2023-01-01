/* file esercizio18.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 5; j >= 1; j--) {
			if (i == j) cout << i;
			else cout << " ";
		}
		cout << endl;
	}
}

