/* file esercizio4.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	double a = 2.5;

	// dichiara un puntatore "generico" a void*

	void *vPtr = &a;

	cout << "Variabile originale: " << a << endl;

	double *aPtr = static_cast<double*>(vPtr);

	*aPtr *= *aPtr;

	cout << "Variabile al quadrato: " << a << endl;
}

