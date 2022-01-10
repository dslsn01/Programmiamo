/* file overloading.cpp */

#include <iostream>

using std::cout;
using std::endl;

void f(int a) 
{
	cout << "f(" << a << ");" << endl;
}

void f(int a, int b) 
{
	cout << "f(" << a << ", " << b << ");" << endl;
}

void f(double a, double b) 
{
	cout << "f(" << a << ", " << b << ");" << endl;
}

int main() 
{
	f(1);
	f(1, 2);
	f(3.14, 2.71);
}

