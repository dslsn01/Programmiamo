/*
file func.cpp
compilare con: g++ -std=c++11 func.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
	vector<int> nums(10);
	iota(nums.begin(), nums.end(), 1);

	vector<int> sq(10);
	transform(nums.begin(), nums.end(), sq.begin(), [](const int n) { return n*n; } );

	cout << "[";
	copy(sq.begin(), sq.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

