/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp
*/

#include <iostream>
#include <iterator>
#include <array>

using std::cout;
using std::endl;
using std::array;
using std::ostream_iterator;

int main()
{
	array<int, 10> a;

	for (int i = 0, j = 2; i < 10; i++, j += 2) {
		if (j % 2 == 0) {
			a[i] = j;
		}
	}

	array<int, 10> b;

	for (int i = 0, j = 3; i < 10; i++, j += 3) {
		if (j % 3 == 0) {
			b[i] = j;
		}
	}

	cout << "[";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "[";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "Elementi comuni: ";

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				cout << a[i] << " ";
			}
		}
	}

	cout << endl;
}

