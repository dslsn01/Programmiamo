/* file exceptionPropagation.cpp */

#include <iostream>
#include <stdexcept>

using std::cerr;
using std::endl;
using std::runtime_error;

/* la funzione propagate() solleva un'eccezione generica */

void propagate()
{
	throw runtime_error("Sollevata un'eccezione!");
}

/* la funzione chiamante main() invoca la funzione propagate() e gestisce l'eccezione */

int main()
{
	try {
		propagate();
	}
	catch (runtime_error &e) {
		cerr << e.what() << endl;
	}
}

