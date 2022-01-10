/*
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp
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
	set<int> a = {1, 2, 3};
	set<int> b = {3, 4, 5};
	set<int> c = {-1, 0, 1};

	cout << "A = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "B = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "C = [";
	copy(c.begin(), c.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* calcola la differenza tra A e B: tutti gli elementi di A non presenti in B */

	set<int> diff_ab;
	set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(diff_ab, diff_ab.begin()));

	cout << "Differenza tra A e B: [";
	copy(diff_ab.begin(), diff_ab.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* calcola la differenza tra (A - B) e C: tutti gli elementi di A non presenti in B nè in C */

	set<int> diff_ab_c;
	set_difference(diff_ab.begin(), diff_ab.end(), c.begin(), c.end(), inserter(diff_ab_c, diff_ab_c.begin()));

	cout << "Differenza tra (A - B) e C: [";
	copy(diff_ab_c.begin(), diff_ab_c.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

