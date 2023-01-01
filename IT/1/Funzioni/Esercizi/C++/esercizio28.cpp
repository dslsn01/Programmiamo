/* file esercizio28.cpp */

#include <iostream>

using std::cout;
using std::endl;

int fibonacci(int);

int main() 
{
	for (int i = 1; i <= 20; i++) {
		cout << fibonacci(i) << " ";
	}

	cout << endl;
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;

	for (int i = 0; i < n; i++) {
		int prevA = a;
		a = b;
		b = prevA + b;
	}

	return a;
}

