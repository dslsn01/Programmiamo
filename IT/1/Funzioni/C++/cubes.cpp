/* file cubes.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main() 
{
	/* dichiara tre variabili */

	int n1 = 3;
	int n2 = 4; 
	int n3 = 5;

	/* calcola i cubi */

	int cube1 = n1 * n1 * n1;
	int cube2 = n2 * n2 * n2;
	int cube3 = n3 * n3 * n3; 

	/* stampa i cubi */

	cout << n1 << " al cubo = " << cube1 << endl;
	cout << n2 << " al cubo = " << cube2 << endl;
	cout << n3 << " al cubo = " << cube3 << endl;
}

