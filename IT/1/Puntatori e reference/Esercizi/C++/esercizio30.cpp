/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp
*/

#include <iostream>
#include <iterator>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::begin;
using std::end;

int* map(int*, const int, void (*callback)(int*));
void square(int*);
void cube(int*);
void pow4(int*);

int main()
{
	void (*func[3])(int*);

	func[0] = square;
	func[1] = cube;
	func[2] = pow4;

	int arr[] = {2, 3, 4, 5, 6, 7};
	const int LEN = sizeof(arr)/sizeof(int);

	cout << "[";
	copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	for (auto& f : func) {
		int* buff = map(arr, LEN, f);

		cout << "[";
		copy(buff, buff+LEN, ostream_iterator<int>(cout, ", "));
		cout << "\b\b]" << endl;

		delete [] buff;
	}
}

int* map(int* arr, const int LEN, void (*callback)(int*)) {
	int* buff = new int[LEN]();
	copy(arr, arr+LEN, buff);

	for (int i = 0; i < LEN; i++) {
		callback(&buff[i]);
	}

	return buff;
}

void square(int* n) {
	*n *= *n;
}

void cube(int* n) {
	*n *= (*n) * (*n);
}

void pow4(int* n) {
	*n = pow(*n, 4);
}

