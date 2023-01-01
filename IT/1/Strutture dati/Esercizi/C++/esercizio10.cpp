/*
file esercizio10.cpp
compilare con: g++ -std=c++11 esercizio10.cpp
*/

#include <iostream>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::reverse_copy;
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

	reverse_copy(begin(nums), end(nums), vcopy);

	cout << "[";
	copy(begin(vcopy), end(vcopy), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

