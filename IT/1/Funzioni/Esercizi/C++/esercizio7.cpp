/* file esercizio7.cpp */

#include <iostream>

using std::cout;
using std::endl;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() 
{
	int a = 5;
	int b = 10;
	int c = 15;

	cout << "Massimo tra " << a << " e " << b << ": " << max(a, b) << endl;
	cout << "Massimo tra " << b << " e " << c << ": " << max(b, c) << endl;
}

