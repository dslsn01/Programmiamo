/* file esercizio1.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 2;
	int *aPtr = &a;

	cout << "Variabile originale: " << a << endl;

	// notare l'asterisco "*": azzera la variabile puntata

	*aPtr = 0;

	cout << "Variabile azzerata: " << a << endl;
}

