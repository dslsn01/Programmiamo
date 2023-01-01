/* file functionCube.cpp */

#include <iostream>

using std::cout;
using std::endl;

/* definizione della funzione cube() */

int cube(const int n)
{
	int cube = n * n * n;
	return cube;
}

int main() 
{
	/* dichiara tre variabili */

	int n1 = 3;
	int n2 = 4;
	int n3 = 5;

	/* calcola i cubi invocando la funzione cube() */

	int cube1 = cube(n1);
	int cube2 = cube(n2);
	int cube3 = cube(n3);

	/* stampa i cubi */

	cout << n1 << " al cubo = " << cube1 << endl;
	cout << n2 << " al cubo = " << cube2 << endl;
	cout << n3 << " al cubo = " << cube3 << endl;
}

