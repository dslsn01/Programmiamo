/* file esercizio5.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

int main()
{
	int a = 10;

	int *ptr1 = &a;
	int *ptr2 = &a;

	// i due puntatori puntano allo stesso indirizzo di memoria

	cout << "ptr1 = " << ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;

	// valore della variabile puntata

	cout << "*ptr1 -> " << *ptr1 << ", *ptr2 -> " << *ptr2 << endl;

	cout << "I due puntatori sono uguali? " << boolalpha << (ptr1 == ptr2) << endl;

	int b = a;
	ptr2 = &b;

	// ora i due puntatori puntano a un diverso indirizzo di memoria

	cout << "ptr1 = " << ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;

	// ...ma il valore delle variabili puntate è lo stesso

	cout << "*ptr1 -> " << *ptr1 << ", *ptr2 -> " << *ptr2 << endl;

	cout << "I due puntatori sono uguali? " << boolalpha << (ptr1 == ptr2) << endl;
}

