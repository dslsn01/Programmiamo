/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
*/

#include <iostream>
#include <iomanip>
#include <iterator>
#include <random>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::setprecision;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::vector;
using std::sort;

int main()
{
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> rrange(1, 10);
	int r_size = rrange(gen)*5;
	vector<int> nums;

	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < r_size; i++) {
		nums.push_back(dist(gen));
	}

	sort(nums.begin(), nums.end());

	cout << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	int i = nums.size() / 2;

	if (nums.size() % 2 != 0) {
		cout << "Mediana: " << setprecision(3) << nums[i] << "." << endl;
	}
	else {
		int j = i-1;
		double mdn = ((double)nums[i] + nums[j])/2;
		cout << "Mediana: " << setprecision(3) << mdn << "." << endl;
	}
}

