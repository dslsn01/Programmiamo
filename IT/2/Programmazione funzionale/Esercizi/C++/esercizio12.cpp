/*
file esercizio12.cpp
compilare con: g++ -std=c++11 esercizio12.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
	vector<int> v(100);
	iota(v.begin(), v.end(), 1);

	vector<int> o;
	copy_if(v.begin(), v.end(), inserter(o, o.begin()), [](const int n) {
		return n % 2 == 1;
	});

	vector<int> m;
	copy_if(o.begin(), o.end(), inserter(m, m.begin()), [](const int n) {
		return n % 3 == 0;
	});

	cout << "[";
	copy(m.begin(), m.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

