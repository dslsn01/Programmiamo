/*
file esercizio27.cpp
compilare con: g++ -std=c++11 esercizio27.cpp
*/

#include <iostream>
#include <iterator>
#include <memory>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::shared_ptr;

void dtor(int *arr) {
	cout << "Libero la memoria." << endl;
	delete [] arr;
}

shared_ptr<int> f1(const int LEN) {
	shared_ptr<int> arr(new int[LEN](), dtor);
	return arr;
}

void f2(shared_ptr<int> arr, const int LEN) {
	for (int i = 0, j = 1; i < LEN; i++, j++) {
		arr.get()[i] = j;
	}
}

int main()
{
	const int LEN = 10;
	auto arr = f1(LEN);

	cout << "[";
	copy(arr.get(), arr.get()+LEN, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	f2(arr, LEN);

	cout << "[";
	copy(arr.get(), arr.get()+LEN, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

