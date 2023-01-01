/*
file esercizio11.cpp
compilare con: g++ -std=c++11 esercizio11.cpp
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

	const int LEN = sizeof(nums) / sizeof(int);

	for (int i = 0, j = LEN-1; i < LEN / 2; i++, j--) {
		int z = nums[j];
		nums[j] = nums[i];
		nums[i] = z;
	}

	cout << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

