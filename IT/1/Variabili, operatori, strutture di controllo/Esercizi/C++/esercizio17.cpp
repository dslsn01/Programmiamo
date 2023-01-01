/* file esercizio17.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i == j) cout << i;
			else cout << " ";
		}
		cout << endl;
	}
}

