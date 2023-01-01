/* file funcPtr.cpp */

#include <iostream>

using std::cout;
using std::endl;

void f1()
{
	cout << "f1()" << endl;
}

int main() 
{
	/* dichiara un puntatore a funzione */

	void (*function)() = NULL;

	/* inizializza il puntatore a funzione perché punti alla funzione f1() */

	function = f1;

	/* invoca la funzione f1() tramite il puntatore */

	function();
}

