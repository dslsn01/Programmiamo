/* file esercizio20.cpp */

#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	const int LEN = 10;
	int *arr = new int[LEN];

	// inizializza gli elementi dell'array al contrario: da arr[9] ad arr[0]

	for (int i = LEN-1, j = 1; i >= 0; i--, j++) {
		*(arr + i) = j*j;
	}

	for (int i = 0; i < LEN; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	delete [] arr;
}

