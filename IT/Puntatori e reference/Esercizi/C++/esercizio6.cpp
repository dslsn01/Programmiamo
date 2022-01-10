/* file esercizio6.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 2;
	int *ptr1 = &a;

	// con l'operatore "=" copia la variabile di tipo "puntatore"

	int *ptr2 = ptr1;

	cout << "Variabile originale: " << a << endl;

	// i puntatori puntano allo stesso indirizzo di memoria

	cout << "ptr1 = " << ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;

	// entrambi i puntatori decrementano la stessa variabile

	*ptr1 -= 1;
	*ptr2 -= 1;

	cout << "Variabile azzerata: " << a << endl;
}

