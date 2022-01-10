/*
file esercizio23.cpp
compilare con: g++ -std=c++11 esercizio23.cpp
*/

#include <iostream>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::copy;
using std::begin;
using std::end;
using std::ostream_iterator;

void square(int*, const int);

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout << "Array originale: " << endl;

	copy(begin(arr), end(arr), ostream_iterator<int>(cout, " "));
	cout << endl;

	square(arr, sizeof(arr)/sizeof(int));

	cout << "Array (elementi al quadrato): " << endl;

	copy(begin(arr), end(arr), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void square(int *arr, const int LEN) {
	for (int i = 0; i < LEN; i++) {
		int n = *(arr + i);
		*(arr + i) = n * n;
	}
}

