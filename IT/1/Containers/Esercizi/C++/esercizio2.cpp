/*
file esercizio2.cpp
compilare con: g++ -std=c++11 esercizio2.cpp
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> nums = {1, 3, 5, 7, 9};

	for (int i = nums.size() - 1; i >= 0; i--) {
		cout << nums[i] << " ";
	}

	cout << endl;
}

