/*
file esercizio26.cpp
compilare con: g++ -std=c++11 esercizio26.cpp
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
	set<int> b = {2, 3, 4};
	set<int> c = {3, 4, 5};

	cout << "A = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "B = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "C = [";
	copy(c.begin(), c.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	// buffer temporaneo per la differenza simmetrica tra A e B
	set<int> buffer;
	set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(buffer, buffer.begin()));

	set<int> s_diff;
	set_symmetric_difference(buffer.begin(), buffer.end(), c.begin(), c.end(), inserter(s_diff, s_diff.begin()));

	cout << "Differenza simmetrica tra gli insiemi A, B e C: [";
	copy(s_diff.begin(), s_diff.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

