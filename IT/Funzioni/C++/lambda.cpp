/*
file lambda.cpp
compilare con: g++ -std=c++11 lambda.cpp
*/

#include <iostream>

using std::cout;
using std::endl;

int main() 
{
	int n = 3;

	// dichiara una funzione lambda (anonima)
	auto f = [](int n) { return n * n; };

	int square = f(n);

	cout << n << " al quadrato = " << square << endl;
}

