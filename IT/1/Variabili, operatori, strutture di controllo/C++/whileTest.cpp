/* file whileTest.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main() 
{
	/* inizializza la variabile contatore */

	int c = 0;

	/* itera per cinque volte */

	while (c < 5) {
		cout << c << " ";
		c++;
	}

	/* fine del ciclo */

	cout << endl;
	cout << "Fine del ciclo." << endl;
}

