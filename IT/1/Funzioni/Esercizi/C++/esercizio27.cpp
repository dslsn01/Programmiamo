/* file esercizio27.cpp */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void pFact(int n, int f, vector<int>& fact);

int main() {
	for (int i = 4; i < 20; i++) {
		vector<int> fact;
		pFact(i, 2, fact);
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

void pFact(int n, int f, vector<int>& fact) {
	if (n < 2) return;
	if (n % f == 0) {
		pFact(n/f, f, fact);
		fact.push_back(f);
	}
	else {
		pFact(n, ++f, fact);
	}
}

