/* file bitwiseops.cpp */

#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

int main() {
	// insieme A: numeri pari
	int a = 0;

	// insieme B: numeri dispari
	int b = 0;

	// insieme C: multipli di 3, pari e dispari
	int c = 0;

	for (int i = 2; i < 32; i++) {
		if ((i & 1) == 0) {
			a |= (1 << i);
		}
	}

	for (int i = 0; i < 32; i++) {
		if ((i & 1) == 1) {
			b |= (1 << i);
		}
	}

	for (int i = 3; i < 32; i += 3) {
		c |= (1 << i);
	}

	// stampa gli elementi di A

	cout << "A = {" << bitset<32>(a) << "}" << endl;

	for (int i = 2; i < 32; i++) {
		if (a & (1 << i)) {
			cout << i << " ";
		}
	}

	cout << endl;

	// stampa gli elementi di B

	cout << "B = {"  << bitset<32>(b) << "}" << endl;

	for (int i = 1; i < 32; i++) {
		if (b & (1 << i)) {
			cout << i << " ";
		}
	}

	cout << endl;

	// stampa gli elementi di C

	cout << "C = {" << bitset<32>(c) << "}" << endl;

	for (int i = 3; i < 32; i++) {
		if (c & (1 << i)) {
			cout << i << " ";
		}
	}

	cout << endl;

	// unione insiemistica A u B

	int aub = a | b;

	cout << "A u B = {" << bitset<32>(aub) << "}" << endl;

	for (int i = 0; i < 32; i++) {
		if (aub & (1 << i)) {
			cout << i << " ";
		}
	}

	cout << endl;

	// intersezione insiemistica: B & C (multipli di tre che sono dispari)

	int bec = b & c;

	cout << "B & C = {" << bitset<32>(bec) << "}" << endl;

	for (int i = 0; i < 32; i++) {
		if (bec & (1 << i)) {
			cout << i << " ";
		}
	}

	cout << endl;

	// complemento (A u B) \ C (pari e dispari meno i multipli di tre)

	int aub_c = aub & ~c;

	cout << "(A u B) \\ C = {" << bitset<32>(aub_c) << "}" << endl;

	for (int i = 0; i < 32; i++) {
		if (aub_c & (1 << i)) {
			cout << i << " ";
		}
	}

	cout << endl;

	// differenza simmetrica B ^ C: numeri dispari oppure pari multipli di tre

	int b_c = b ^ c;

	cout << "B ^ C = {" << bitset<32>(b_c) << "}" << endl;

	for (int i = 0; i < 32; i++) {
		if (b_c & (1 << i)) {
			cout << i << " ";
		}
	}

	cout << endl;
}

