/* file esercizio5.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int nums[] = {1, 3, 5, 7, 9};

	for (int i = sizeof(nums) / sizeof(int) - 1; i >= 0; i--) {
		cout << i << ") " << nums[i] << endl;
	}
}

