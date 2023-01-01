/*
file esercizio3.cpp
compilare con: g++ -std=c++11 esercizio3.cpp
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> nums = {1, 3, 5, 7, 9};

	for (int n : nums) {
		cout << n << " ";
	}

	cout << endl;
}

