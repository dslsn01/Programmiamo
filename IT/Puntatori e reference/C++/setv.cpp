/* file setv.cpp */

#include <iostream>

using std::cout;
using std::endl;

/* la prima versione della funzione riceve un solo parametro, e ha tipo di ritorno int */

int f1(int a) 
{
	return a + 1;
}

/* la seconda versione della funzione riceve tre puntatori, e ha tipo di ritorno void */

void f2(int *a, int *b, int *c) 
{
	*a += 1;
	*b += 1;
	*c += 1;
}

int main() 
{
	int a = 1;
	int b = 2;
	int c = 3;

	/* senza usare i puntatori, sono necessarie tre invocazioni di funzione per incrementare le variabili a, b, c */

	a = f1(a);
	b = f1(b);
	c = f1(c);

	cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

	/* utilizzando i puntatori, una sola invocazione di funzione è sufficiente a incrementare  tre variabili */

	f2(&a, &b, &c);

	cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}

