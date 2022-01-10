/*
file esercizio27.cpp
compilare con: g++ -std=c++11 esercizio27.cpp
*/

#include <iostream>
#include <iterator>
#include <random>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

int main()
{
	const int LEN = 100;
	int nums[LEN];

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(0, 99);

	for (int i = 0; i < LEN; i++) {
		nums[i] = dist(gen);
	}

	cout << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	int counts[LEN];
	int md = 1;

	for (int i = 0; i < LEN; i++) {
		int c = nums[i];
		counts[c]++;
		if (counts[c] > md) {
			md = counts[c];
		}
	}

	if (md == 1) {
		cout << "L'array non ha una moda." << endl;
		return 0;
	}

	cout << "Moda (" << md << " occorrenze): ";

	int j = 0;
	for (int i = 0; i < LEN; i++) {
		if (counts[i] == md) {
			if (j > 0) cout << ", ";
			cout << i;
			j++;
		}
	}

	cout << "." << endl;
}

