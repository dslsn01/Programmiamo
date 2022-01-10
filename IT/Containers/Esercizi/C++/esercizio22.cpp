/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp
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
	set<int> a = {0, 1, 2};
	set<int> b = {3, 4, 5};
	set<int> c = {2, 3, 4};

	cout << "A = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "B = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "C = [";
	copy(c.begin(), c.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* calcola l'intersezione insiemistica di A e B: se è vuota, gli insiemi sono disgiunti */

	set<int> a_b;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(a_b, a_b.begin()));

	if (a_b.size() == 0) {
		cout << "Gli insiemi A e B sono disgiunti!" << endl;
	}

	/* se l'intersezione di A e C non è vuota, stampa gli elementi comuni */

	set<int> a_c;
	set_intersection(a.begin(), a.end(), c.begin(), c.end(), inserter(a_c, a_c.begin()));

	if (a_c.size() != 0) {
		cout << "Gli insiemi A e C hanno elementi comuni: [";
		copy(a_c.begin(), a_c.end(), ostream_iterator<int>(cout, ", "));
		cout << "\b\b]" << endl;
	}
}

