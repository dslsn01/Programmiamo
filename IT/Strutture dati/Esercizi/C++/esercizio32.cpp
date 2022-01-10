/*
file esercizio32.cpp
compilare con: g++ -std=c++11 esercizio32.cpp
*/

#include <iostream>
#include <iterator>
#include <random>

using std::cout;
using std::endl;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::begin;
using std::end;
using std::ostream_iterator;

int main()
{
	const int N = 10;
	int nums[N];

	default_random_engine gen(random_device{}());

	for (int i = 0; i < N; i++) {
		uniform_int_distribution<int> dist(2, 100);
		int r = dist(gen);
		nums[i] = r;
	}

	cout << "Array originale: " << endl << "[";

	for (int i = 0; i < N; i++) {
		cout << nums[i];
		if (i < N-1) cout << ", ";
	}

	cout << "]" << endl;

	int n = N - 1;

	int lc = n;
	while (lc > 0) {
		lc = 0;
		for (int i = 0; i < n; i++) {
			int n1 = nums[i];
			int n2 = nums[i+1];
			// ordine decrescente
			if (n1 < n2) {
				nums[i] = n2;
				nums[i+1] = n1;
			}
			lc = i;
		}
		n = lc;
	}

	cout << "Array ordinato:" << endl << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

