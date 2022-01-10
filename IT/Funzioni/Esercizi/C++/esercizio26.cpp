/* file esercizio26.cpp */

#include <iostream>
#include <cmath>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void pFact(int n, vector<int>& fact);

int main() {
	for (int i = 4; i < 20; i++) {
		vector<int> fact;
		pFact(i, fact);
		cout << i;
		if (fact.size() > 1) {
			cout << " = ";
			for (int j = 0; j < fact.size(); j++) {
				cout << fact[j];
				if (j < fact.size()-1) cout << " * ";
			}
			cout << endl;
		}
		else {
			cout << " primo." << endl;
		}
	}
}

void pFact(int n, vector<int>& fact) {
	if (n <= 3) return;
	int m = n;
	double sr = sqrt(n);
	for (int f = 2; f < (int)sr+1; f++) {
		while (m % f == 0) {
			fact.push_back(f);
			m = m / f;
		}
	}
	if (m > 1) fact.push_back(m);
}

