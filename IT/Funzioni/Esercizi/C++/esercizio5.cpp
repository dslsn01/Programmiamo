/* file esercizio5.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

bool comp(int a, int b) {
	return a > b;
}

int main() 
{
	int a = 5;
	int b = 10;

	cout << a << " > " << b << "? " << boolalpha << comp(a, b) << endl;
	cout << b << " > " << a << "? " << boolalpha << comp(b, a) << endl;
}

