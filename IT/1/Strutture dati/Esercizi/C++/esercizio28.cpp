/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
*/

#include <iostream>
#include <iomanip>
#include <iterator>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;
using std::setprecision;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;

int main()
{
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> rrange(1, 20);

	const int LEN = rrange(gen) * 5;
	int *nums = new int[LEN];

	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < LEN; i++) {
		nums[i] = dist(gen);
	}

	sort(nums, nums+LEN);

	cout << "[";
	copy(nums, nums+LEN, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	double mdn = 0;
	int i = LEN / 2;

	if (LEN % 2 != 0) {
		mdn = nums[i];
	}
	else {
		int j = i-1;
		mdn = ((double) nums[j] + nums[i]) / 2;
	}

	cout << "Mediana: " << setprecision(3) << mdn << "." << endl;

	delete [] nums;
}

