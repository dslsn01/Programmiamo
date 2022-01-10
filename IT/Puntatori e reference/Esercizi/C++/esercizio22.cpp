/* file esercizio22.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	// array di interi
	int arr1[3] = {1, 2, 3};

	// array di puntatori a interi: notare l'asterisco "*"
	int *arr2[3];

	for (int i = 0; i < 3; i++) {
		arr2[i] = &arr1[i];
	}

	cout << "[";
	for (int i = 0; i < 3; i++) {
		cout << *(arr1 + i) << ", ";
	}
	cout << "\b\b]" << endl;

	cout << "[";

	// notare il doppio asterisco "**"

	for (int i = 0; i < 3; i++) {
		cout << **(arr2 + i) << ", ";
	}

	cout << "\b\b]" << endl;
}

