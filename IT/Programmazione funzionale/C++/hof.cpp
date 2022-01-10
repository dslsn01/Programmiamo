/*
file hof.cpp
compilare con: g++ -std=c++11 hof.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
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
	uniform_int_distribution<int> dist(1, 100);

	auto generator = [&dist, &gen] () {
		return dist(gen);
	};

	vector<int> nums(20);
	generate(nums.begin(), nums.end(), generator);

	auto cmp = [] (int& m, int& n) {
		bool m_e = (m % 2 == 0);
		bool n_e = (n % 2 == 0);
		// se m e n sono entrambi pari o entrambi dispari
		if (m_e && n_e || !m_e && !n_e) return m < n;
		return (m_e && !n_e) ? true : false;
	};

	vector<int> li(nums.size());
	partial_sort_copy(nums.begin(), nums.end(), li.begin(), li.end(), cmp);

	cout << "Lista originale:" << endl << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
	cout << "Numeri pari a destra, dispari a sinistra:" << endl << "[";
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

