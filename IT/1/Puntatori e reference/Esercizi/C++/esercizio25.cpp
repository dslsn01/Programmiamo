/*
file esercizio25.cpp
compilare con: g++ -std=c++11 esercizio25.cpp
*/

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;

int scalpro(int*, int*, const int);

int main()
{
	int v1[] = {1, 2, 3};
	int v2[] = {3, 2, 1};

	cout << "(";
	copy(begin(v1), end(v1), ostream_iterator<int>(cout, ", "));
	cout << "\b\b) X (";
	copy(begin(v2), end(v2), ostream_iterator<int>(cout, ", "));
	cout << "\b\b) = ";

	int result = scalpro(v1, v2, sizeof(v1)/sizeof(int));

	cout << result << endl;
}

int scalpro(int* v1, int* v2, const int LEN) {
	int result = 0;
	for( int i = 0; i < LEN; i++) {
		result += v1[i] * v2[i];
	}
	return result;
}

