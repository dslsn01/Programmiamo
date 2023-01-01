/*
file esercizio17.cpp
compilare con: g++ -std=c++11 esercizio17.cpp
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

double avg(vector<int>& v) {
	return accumulate(v.begin(), v.end(), 0) / (double) v.size();
}

int main() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	vector<int> v(25);
	generate(v.begin(), v.end(), bind(dist, ref(gen)));

	double m = avg(v);

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "Media: " << m << endl;
}

