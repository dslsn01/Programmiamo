/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp
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

void swap(int[], const int);

int main() 
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout << "Array originale: " << endl;

	copy(begin(arr), end(arr), ostream_iterator<int>(cout, " "));
	cout << endl;

	swap(arr, sizeof(arr)/sizeof(int));

	cout << "Array (elementi invertiti): " << endl;

	copy(begin(arr), end(arr), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void swap(int arr[], const int LEN) {
	for (int i = 0, j = LEN-1; i < LEN / 2; i++, j--) {
		int z = arr[j];
		arr[j] = arr[i];
		arr[i] = z;
	}
}

