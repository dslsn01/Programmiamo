/* file esercizio31.cpp */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory>

using std::cout;
using std::endl;
using std::copy;

int* pFact(int, int*);

int main() {
	for (int i = 4; i < 20; i++) {
		int nFact = 0;
		int* fact = pFact(i, &nFact);
		cout << i;
		if (nFact > 1) {
			cout << " = ";
			for (int j = 0; j < nFact; j++) {
				cout << fact[j];
				if (j < nFact-1) cout << " * ";
			}
			cout << endl;
		}
		else {
			cout << " primo." << endl;
		}

		delete [] fact;
	}
}

int* pFact(int n, int* nFact) {
	if (n <= 3) return NULL;
	int chunk = 5;
	int* fact = new int[chunk];
	int i = 0;
	int m = n;
	for (int f = 2; f < (int) sqrt(n)+1; f++) {
		while (m % f == 0) {
			*nFact += 1;
			if (*nFact >= chunk) {
				int _chunk = chunk + 5;
				int* newFact = new int[_chunk];
				copy(fact, fact+chunk, newFact);
				delete [] fact;
				chunk = _chunk;
				fact = newFact;
			}
			fact[i] = f;
			m = m / f;
			i++;
		}
	}
	if (m > 1) {
		fact[i] = m;
		*nFact += 1;
	}

	// rialloca un array con l'esatto numero di fattori

	int *dFact = new int[*nFact];
	copy(fact, fact+*nFact, dFact);
	delete [] fact;
	fact = dFact;

	return fact;
}

