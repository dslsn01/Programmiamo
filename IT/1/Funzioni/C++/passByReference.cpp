/* file passByReference.cpp */

#include <iostream>

using std::cout;
using std::endl;

void resetArray(int arr[]) {
	for (int i = 0; i < 3; i++) {
		arr[i] = 0;
	}
}

int main()
{
	int arr[] = {1, 2, 3};

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	resetArray(arr);

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

