/* file doWhileTest.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main() 
{
	/* inizializza la variabile contatore */

	int c = 5;

	/* esegue una prima volta le istruzioni nel ciclo, quindi itera finché la variabile contatore è minore di 5 */

	do {
		cout << c << endl;
	}
	while (c < 5);

	cout << "Fine del ciclo." << endl;
}

