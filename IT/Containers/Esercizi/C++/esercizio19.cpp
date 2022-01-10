/*
file esercizio19.cpp
compilare con: g++ -std=c++11 esercizio19.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::set;

int main()
{
	set<int> a = {0, 1, 2, 3, 4, 5, 6, 7};

	cout << "A = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* stampa la cardinalità di A, il suo massimo e minimo */

	cout << "Cardinalità dell'insieme A: " << a.size() << endl;

	/* poichè il set è già ordinato, l'elemento più grande e il più piccolo si trovano agli estremi */

	auto min = a.begin();
	auto max = a.rbegin();

	cout << "Elemento minore dell'insieme A: " << *min << endl;
	cout << "Elemento maggiore dell'insieme A: " << *max << endl;
}

