/* file esercizio18.cpp */

#include <iostream>

using std::cout;
using std::endl;

void swap(int**, int**);

int main()
{
	int a = 1;
	int b = 2;

	int *ptr1 = &a;
	int *ptr2 = &b;

	cout << "ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;

	swap(&ptr1, &ptr2);

	cout << "ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;
}

void swap(int** a, int** b) {
	int *c = *a;
	*a = *b;
	*b = c;
}

