/* file testRef2.cpp */

#include <iostream>

using std::cout;
using std::endl;

/* la funzione f1() riceve un puntatore come parametro */

void f1(int* a)
{
	*a += 1;
}

/* la funzione f2() riceve un reference come parametro */

void f2(int& b) 
{
	b += 1;
}

int main()
{
	int a = 1;

	cout << "Valore della variabile: " << a << endl;

	/* incrementa la variabile a con un puntatore */

	f1(&a);

	cout << "Valore della variabile: " << a << endl;

	/* incrementa la variabile a con un reference */

	f2(a);

	cout << "Valore della variabile: " << a << endl;
}

