/* file esercizio29.cpp */

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
	if (n <= 1) {
		return n;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

