/* file esercizio2.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 2;
	int *aPtr = &a;

	cout << "Valore del puntatore: " << aPtr << endl;
	cout << "Variabile puntata: " << a << endl;

	// azzera l'indirizzo di memoria del puntatore, che non punta più alla variabile 'a'

	aPtr = 0;

	cout << "Valore del puntatore: " << aPtr << endl;
	cout << "Variabile puntata: " << a << endl;
}

