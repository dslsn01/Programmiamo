/*
file esercizio26.cpp
compilare con: g++ -std=c++11 esercizio26.cpp
*/

#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;

int main()
{
	const int LEN = 10;
	int nums[LEN];

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 10);

	for (int i = 0; i < LEN; i++) {
		int r = dist(gen);
		nums[i] = r;
	}

	cout << "Array originale: " << endl << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	sort(begin(nums), end(nums));

	cout << "Array ordinato: " << endl << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	int i = 0;
	int d = 0; // conteggio duplicati

	while (i < LEN) {
		if (nums[i] != -1) {
			int n = nums[i];
			int j = i+1;
			while (j < LEN && n == nums[j]) {
				nums[j] = -1;
				d++;
				j++;
			}
		}
		i++;
	}

	const int ULEN = LEN-d;
	int uniques[ULEN];

	for (int j = 0, k = 0; j < LEN; j++) {
		if (nums[j] != -1) {
			uniques[k] = nums[j];
			k++;
		}
	}

	cout << "Array senza elementi duplicati: " << endl << "[";
	copy(uniques, uniques+ULEN, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

