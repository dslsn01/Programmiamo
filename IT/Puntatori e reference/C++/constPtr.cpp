/* file constPtr.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 1;
	int b = 2;

	/* stampa il valore di a e b, modificati con il puntatore aPtr */

	cout << "a = " << a << ", b = " << b << endl;

	/* puntatore variabile a dati variabili */

	int *aPtr = &a;

	*aPtr += 1;
	aPtr = &b;
	*aPtr += 1;

	cout << "a = " << a << ", b = " << b << endl;

	/* puntatore costante a dati variabili: non si può reinizializzare per puntare a una diversa variabile */

	int * const constPtr = &a;

	*constPtr += 1;

	/* constPtr = &b; */ // errore!

	/* stampa il valore di a, modificato con il puntatore constPtr */

	cout << "a = " << a << endl;

	/* puntatore variabile a dati costanti: non si può usare per modificare la variabile puntata */

	const int *constValue = &a;

	/* *constValue += 1; */	// errore!

	constValue = &b;

	cout << "b = " << *constValue << endl;

	/* puntatore costante a dati costanti: non si può usare per modificare la variabile puntata, e non può essere reinizializzato per puntare a una diversa variabile */

	const int * const blocked = &a;

	/* stampa il valore della variabile b dopo aver reinizializzato il puntatore constValue */

	cout << "a = " << *blocked << endl;
}

