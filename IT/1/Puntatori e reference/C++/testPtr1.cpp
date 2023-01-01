/* file testPtr1.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	/* dichiara una variabile intera */

	int a = 1;

	/* dichiara una variabile di tipo puntatore a un intero */

	int *aPtr = NULL;

	/* inizializza il puntatore */

	aPtr = &a;

	cout << "Variabile originale: " << a << endl;
	cout << "Valore del puntatore: " << aPtr << endl;

	/* incrementa la variabile a tramite il puntatore */

	*aPtr += 1;

	/* il valore di a è stato modificato */

	cout << "Variabile puntata: " << a << endl << "Puntatore dereferenziato: " << *aPtr << endl;
}

