/*
file esercizio1.cpp
compilare con: g++ -std=c++11 esercizio1.cpp
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> nums = {1, 3, 5, 7, 9};

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}

	cout << endl;
}

