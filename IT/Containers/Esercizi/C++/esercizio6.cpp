/*
file esercizio6.cpp
compilare con: g++ -std=c++11 esercizio6.cpp
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::reverse;

int main()
{
	vector<int> nums = {1, 3, 5, 7, 9};

	cout << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	reverse(nums.begin(), nums.end());

	cout << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

