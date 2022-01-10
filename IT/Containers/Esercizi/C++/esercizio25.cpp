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

	set<int> temp;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(temp, temp.begin()));

	set<int> intersection;
	set_intersection(temp.begin(), temp.end(), c.begin(), c.end(), inserter(intersection, intersection.begin()));

	temp.clear();

	cout << "Intersezione tra gli insiemi A, B e C: [";
	copy(intersection.begin(), intersection.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

