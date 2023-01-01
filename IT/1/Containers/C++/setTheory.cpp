/* 
file setTheory.cpp
compilare con: g++ -std=c++11 setTheory.cpp
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
	/* dichiara due insiemi di numeri interi */

	set<int> a = {0, 1, 2};
	set<int> b = {2, 3, 4};

	cout << "A = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "B = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* unione di A e B */

	set<int> s_union;
	set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(s_union, s_union.begin()));

	cout << "A u B = [";
	copy(s_union.begin(), s_union.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* intersezione di A e B */

	set<int> intersection;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(intersection, intersection.begin()));

	cout << "A & B = [";
	copy(intersection.begin(), intersection.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* differenza tra A e B */

	set<int> diff;
	set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(diff, diff.begin()));

	cout << "A - B = [";
	copy(diff.begin(), diff.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* ...e differenza tra B e A */

	diff.clear();
	set_difference(b.begin(), b.end(), a.begin(), a.end(), inserter(diff, diff.begin()));

	cout << "B - A = [";
	copy(diff.begin(), diff.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* differenza simmetrica tra A e B */

	set<int> s_diff;
	set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(s_diff, s_diff.begin()));

	cout << "A ^ B = [";
	copy(s_diff.begin(), s_diff.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

