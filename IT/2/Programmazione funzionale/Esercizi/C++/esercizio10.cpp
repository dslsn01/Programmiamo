/*
file esercizio10.cpp
compilare con: g++ -std=c++11 esercizio10.cpp
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

	vector<int> e;
	copy_if(v.begin(), v.end(), inserter(e, e.begin()), [](const int n) {
		return n % 2 == 0;
	});

	cout << "[";
	copy(e.begin(), e.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

