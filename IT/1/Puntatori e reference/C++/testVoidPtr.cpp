/* file testVoidPtr.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 1;

	/* dichiara un puntatore "generico" a void* */
	void *vPtr = &a;

	cout << "Variabile originale: " << a << endl;
	cout << "Valore del primo puntatore (void*): " << vPtr << endl;

	/* un puntatore a void* non può essere dereferenziato; il codice commentato non compila */
	// *vPtr += 1;

	/* converte il puntatore generico void* in un puntatore a int* */
	int *aPtr = static_cast<int*>(vPtr);

	*aPtr += 1;

	cout << "Valore del secondo puntatore (int*): " << aPtr << endl;
	cout << "Variabile puntata: " << a << endl;
}

