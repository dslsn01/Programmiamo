/* file esercizio3.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 5;
	double b = 2.5;

	cout << "a = " << a << ", b = " << b << endl;

	double c = a + b;
	/* conversione possibile del risultato a intero, ma perdendo la parte decimale */
	int d = (int)(a + b);

	cout << "a + b (risultato double) = " << c << endl;
	cout << "a + b (convertito a intero) = " << d << endl;
}

