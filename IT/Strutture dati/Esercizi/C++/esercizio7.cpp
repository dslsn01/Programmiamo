/*
file esercizio7.cpp
compilare con: g++ -std=c++11 esercizio7.cpp
*/

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;

int main()
{
	int nums[] = {1, 3, 5, 7, 9};

	cout << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	int tot = 0;

	for (int n : nums) {
		tot += n;
	}

	cout << "Somma degli elementi: " << tot << endl;
}

