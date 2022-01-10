/*
file esercizio4.cpp
compilare con: g++ -std=c++11 esercizio4.cpp
*/

#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main()
{
	vector<int> nums = {1, 3, 5, 7, 9};

	cout << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	int tot = 0;

	for (int n : nums) {
		tot += n;
	}

	cout << "Somma degli elementi: " << tot << endl;
}

