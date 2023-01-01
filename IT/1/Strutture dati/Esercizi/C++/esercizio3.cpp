/* file esercizio3.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int nums[] = {1, 3, 5, 7, 9};

	int i = sizeof(nums) / sizeof(int) - 1;

	while (i >= 0) {
		cout << nums[i] << " ";
		i--;
	}

	cout << endl;
}

