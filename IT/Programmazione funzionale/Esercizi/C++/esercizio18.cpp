/*
file esercizio18.cpp
compilare con: g++ -std=c++11 esercizio18.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>
#include <random>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::generate;
using std::vector;

double mdn(vector<int>& v) {
	vector<int> tmp(v.size());
	partial_sort_copy(v.begin(), v.end(), tmp.begin(), tmp.end());
	int vsize = tmp.size();
	int i = vsize / 2;
	if (vsize % 2 != 0) {
		return tmp[i];
	}
	else {
		int j = i-1;
		return ((double) tmp[j] + tmp[i]) / 2;
	}
}

int main() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> rrange(1, 20);

	vector<int> v(rrange(gen) * 5);

	uniform_int_distribution<int> dist(1, 100);
	generate(v.begin(), v.end(), bind(dist, ref(gen)));

	double m = mdn(v);

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "Mediana: " << m << endl;
}

