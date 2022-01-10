/*
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::begin;
using std::end;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;

int main()
{
	const int LEN = 20;
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	int nums[LEN];

	for (int i = 0; i < LEN; i++) {
		nums[i] = dist(gen);
	}

	cout << "Array originale: " << endl << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	int l = 0;
	int r = LEN-1;

	for (int i = 0; i < LEN; i++) {
		while (nums[l] % 2 == 0) l++;
		while (nums[r] % 2 != 0) r--;
		if (l < r) {
			int tmp = nums[r];
			nums[r] = nums[l];
			nums[l] = tmp;
		}
	}

	cout << "Array originale, numeri pari a destra, dispari a sinistra: " << endl << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]"  << endl;

	int p[l]; // numeri pari

	copy(nums, nums+l, p);
	sort(p, p+l);

	cout << "Numeri pari (ordinati):" << endl << "[";
	copy(p, p+l, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	const int DLEN = LEN-l;
	int dp[DLEN]; // numeri dispari

	copy(nums+l, nums+LEN, dp);
	sort(dp, dp+DLEN);

	cout << "Numeri dispari (ordinati):" << endl << "[";
	copy(dp, dp+DLEN, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

