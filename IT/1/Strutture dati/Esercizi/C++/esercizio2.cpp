/* file esercizio2.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int nums[] = {1, 3, 5, 7, 9};

	int i = 0;

	while (i < sizeof(nums) / sizeof(int)) {
		cout << nums[i] << " ";
		i++;
	}

	cout << endl;
}

