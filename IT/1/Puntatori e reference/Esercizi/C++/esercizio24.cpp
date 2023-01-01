/*
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp
*/

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;

void vscalpro(int, int*, const int);

int main()
{
	int v3d[] = {1, 2, 3};
	int scalar = 3;

	cout << "(";
	copy(begin(v3d), end(v3d), ostream_iterator<int>(cout, ", "));
	cout << "\b\b) * " << scalar << " = ";

	vscalpro(scalar, v3d, sizeof(v3d)/sizeof(int));

	cout << "(";
	copy(begin(v3d), end(v3d), ostream_iterator<int>(cout, ", "));
	cout << "\b\b)" << endl;
}

void vscalpro(int s, int* v, const int LEN) {
	for (int i = 0; i < LEN; i++) {
		*(v + i) *= s;
	}
}

