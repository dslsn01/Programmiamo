/* file esercizio3.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 2;
	int *aPtr = &a;

	cout << "Variabile originale: " << a << endl;

	*aPtr *= *aPtr;

	cout << "Variabile al quadrato: " << a << endl;
}

