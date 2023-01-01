/* file esercizio17.cpp */

#include <iostream>

using std::cout;
using std::endl;

void swap(int*, int*);

int main()
{
	int a = 1;
	int b = 2;

	cout << "a = " << a << ", b = " << b << endl;

	swap(&a, &b);

	cout << "a = " << a << ", b = " << b << endl;
}

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

