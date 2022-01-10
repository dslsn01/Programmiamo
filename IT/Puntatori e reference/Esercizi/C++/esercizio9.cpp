/* file esercizio9.cpp */

#include <iostream>

using std::cout;
using std::endl;

void add(int a, int b, int* result) {
	*result = a + b;
}

int main()
{
	int a = 5;
	int b = 10;

	int result = 0;

	add(a, b, &result);

	cout << a << " + " << b << " = " << result << endl;
}

