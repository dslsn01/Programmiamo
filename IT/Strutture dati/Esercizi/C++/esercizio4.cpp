/* file esercizio4.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int nums[] = {1, 3, 5, 7, 9};

	for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
		cout << i << ") " << nums[i] << endl;
	}
}

