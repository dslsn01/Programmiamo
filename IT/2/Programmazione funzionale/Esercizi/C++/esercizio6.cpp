/*
file esercizio6.cpp
compilare con: g++ -std=c++11 esercizio6.cpp
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
	vector<int> v(10);
	iota(v.begin(), v.end(), 1);

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	vector<int> v2;
	transform(v.begin(), v.end(), inserter(v2, v2.begin()), [](const int n) {
		return n*2;
	});

	cout << "[";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

