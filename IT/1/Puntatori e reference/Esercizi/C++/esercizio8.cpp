/* file esercizio8.cpp */

#include <iostream>

using std::cout;
using std::endl;

void f1(int*);
void f2(int**);
void f3(int***);

int main()
{
	int a = 1;
	cout << "main(): " << a << endl;

	f1(&a);
}

void f1(int* n) {
	cout << "f1(): " << ++(*n) << endl;
	f2(&n);
}

void f2(int** n) {
	cout << "f2(): " << ++(**n) << endl;
	f3(&n);
}

void f3(int*** n) {
	cout << "f3(): " << ++(***n) << endl;
}

