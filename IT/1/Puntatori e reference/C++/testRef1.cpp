/* file testRef1.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 1;

	/* dichiara un reference alla variabile intera a */

	int &aRef = a;

	/* incrementa la variabile a tramite il reference aRef */

	aRef += 1;

	/* il valore di a è stato modificato */

	cout << "a: " << a << endl << "aRef: " << aRef << endl;
}

