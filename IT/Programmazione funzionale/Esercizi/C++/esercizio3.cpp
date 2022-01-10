/*
file esercizio3.cpp
compilare con: g++ -std=c++11 esercizio3.cpp
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

int main() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 10);

	vector<int> v(10);
	generate(v.begin(), v.end(), bind(dist, ref(gen)));

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

