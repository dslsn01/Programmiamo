/*
file esercizio6.cpp
compilare con: g++ -std=c++11 esercizio6.cpp
*/

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int nums[] = {1, 3, 5, 7, 9};

	for (int n : nums) {
		cout << n << " ";
	}

	cout << endl;
}

