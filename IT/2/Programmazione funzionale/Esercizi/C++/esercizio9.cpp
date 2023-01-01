/*
file esercizio9.cpp
compilare con: g++ -std=c++11 esercizio9.cpp
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

	vector<int> m;
	transform(v.begin(), v.end(), inserter(m, m.begin()), [](const int n) {
		return n*6;
	});

	cout << "[";
	copy(m.begin(), m.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

