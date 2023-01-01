/*
file esercizio8.cpp
compilare con: g++ -std=c++11 esercizio8.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::bind;
using namespace std::placeholders;

vector<int> npow(int k, vector<int>& v) {
	auto f = [](const int k, const int p) {
		return pow(k, p);
	};

	auto by2 = bind(f, 2, _1);

	vector<int> p;
	transform(v.begin(), v.end(), inserter(p, p.begin()), by2);

	return p;
}

int main() {
	vector<int> v(10);
	iota(v.begin(), v.end(), 1);

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	vector<int> p = npow(2, v);

	cout << "[";
	copy(p.begin(), p.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

