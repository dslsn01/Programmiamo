/* file esercizio7.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 1;
	int *ptr1 = &a;

	// con l'operatore "&" creo una variabile di tipo "puntatore a un altro puntatore": notare il doppio asterisco "**"

	int **ptr2 = &ptr1;

	cout << "Variabile originale: " << a << endl;

	// i puntatori non puntano allo stesso indirizzo di memoria

	cout << "ptr1 = " << ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;

	*ptr1 += 1;

	// il secondo puntatore dev'essere dereferenziato due volte per accedere alla variabile originale: notare il doppio asterisco "**"

	**ptr2 += 1;

	cout << "Variabile incrementata: " << a << endl;
}

