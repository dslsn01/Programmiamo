/* file esercizio20.cpp */

#include <iostream>

using std::cout;
using std::endl;

double avg(int[], const int);

int main()
{
	int arr1[] = {1, 7, 13};
	int arr2[] = {4, 9, 17, 33, 39};

	cout << "Media tra 1, 7, 13 = " << avg(arr1, sizeof(arr1)/sizeof(int)) << endl;
	cout << "Media tra 4, 9, 17, 33, 39 = " << avg(arr2, sizeof(arr2)/sizeof(int)) << endl;
}

double avg(int arr[], const int LEN) {
	int tot = 0;

	for (int i = 0; i < LEN; i++) {
		tot += arr[i];
	}

	return (double) tot / LEN;
}

