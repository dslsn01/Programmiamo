/*
file esercizio20.cpp
compilare con: g++ -std=c++11 esercizio20.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_set>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::unordered_set;
using std::min_element;
using std::max_element;

int main()
{
	/* l'insieme A non è ordinato */

	unordered_set<int> a = {4, 6, 0, 2, 5, 7, 1, 3};

	cout << "A = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* stampa la cardinalità di A, il suo massimo e minimo */

	cout << "Cardinalità dell'insieme A: " << a.size() << endl;

	/* poichè l'unordered_set non è ordinato, cerchiamo il suo massimo e minimo */

	auto min = min_element(a.begin(), a.end());
	auto max = max_element(a.begin(), a.end());

	cout << "Elemento minore dell'insieme A: " << *min << endl;
	cout << "Elemento maggiore dell'insieme A: " << *max << endl;
}

