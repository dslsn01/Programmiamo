/* file esercizio19.cpp */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	const int LEN = 10;
	int *arr = new int[LEN];

	for (int i = 0, j = 1; i < LEN; i++, j++) {
		*(arr + i) = j*j;
	}

	for (int i = 0; i < LEN; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// libera la memoria allocata in precedenza

	delete [] arr;
}

