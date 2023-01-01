/*
file esercizio9.cpp
compilare con: g++ -std=c++11 esercizio9.cpp
*/

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::copy;
using std::ostream_iterator;
using std::begin;
using std::end;

int main()
{
	int nums[] = {1, 3, 5, 7, 9};

	cout << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	const int LEN = sizeof(nums) / sizeof(int);
	int vcopy[LEN];

	copy(begin(nums), end(nums), begin(vcopy));

	cout << "[";
	copy(begin(vcopy), end(vcopy), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

