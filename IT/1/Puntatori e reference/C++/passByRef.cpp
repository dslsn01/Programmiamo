/* file passByRef.cpp */

#include <iostream>

using std::cout;
using std::endl;

/* la variabile a viene passata per valore: viene incrementata la copia locale della variabile a, e poi restituita */

int f1(int a)
{
	a += 1;
	return a;
}

/* la funzione riceve come argomento un puntatore alla variabile a: il puntatore viene dereferenziato, e viene incrementata la variabile originale */

void f2(int *a) 
{
	*a += 1;
}

int main()
{
	int a = 1;

	/* la funzione f1() riceve una copia della variabile */

	a = f1(a);

	cout << "Valore della variabile: " << a << endl;

	/* la funzione f2() incrementa la variabile originale */

	f2(&a);

	cout << "Valore della variabile: " << a << endl;
}

