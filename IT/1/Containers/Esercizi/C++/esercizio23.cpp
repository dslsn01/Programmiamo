/*
file esercizio23.cpp
compilare con: g++ -std=c++11 esercizio23.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::set;
using std::includes;

int main()
{
	set<int> a = {0, 1, 2, 3, 4};
	set<int> b = {1, 2, 3};

	cout << "A = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "B = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* se tutti gli elementi di B sono anche elementi di A, allora B è un sottoinsieme di A */

	if (includes(a.begin(), a.end(), b.begin(), b.end())) {
		cout << "L'insieme B è un sottoinsieme di A!" << endl;
	}
}

