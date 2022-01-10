/*
file esercizio29.cpp
compilare con: g++ -std=c++11 esercizio29.cpp
*/

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;

void map(int*, const int, void (*callback)(int*));
void square(int*);

int main()
{
	int arr[] = {2, 3, 4, 5, 6, 7};

	cout << "[";
	copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	map(arr, sizeof(arr)/sizeof(int), square);

	cout << "[";
	copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

void map(int* arr, const int LEN, void (*callback)(int*)) {
	for (int i = 0; i < LEN; i++) {
		callback(&arr[i]);
	}
}

void square(int* n) {
	*n *= *n;
}

