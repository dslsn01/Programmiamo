/*
file esercizio11.cpp
compilare con: g++ -std=c++11 esercizio11.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
	vector<int> v(100);
	iota(v.begin(), v.end(), 1);

	vector<int> ps;
	copy_if(v.begin(), v.end(), inserter(ps, ps.begin()), [](const int n) {
		int m = round(sqrt(n));
		return (m*m) == n ? true : false;
	});

	cout << "[";
	copy(ps.begin(), ps.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

