/*
file esercizio17.cpp
compilare con: g++ -std=c++11 esercizio17.cpp
*/

#include <iostream>
#include <iomanip>
#include <iterator>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::setprecision;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::pair;
using std::unordered_map;
using std::vector;
using std::sort;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.second > p2.second;
}

int main()
{
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> rrange(1, 20);
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

	int tot = 0;

	for (auto& n : nums) {
		tot += n;
	}

	cout << "Media: " << setprecision(3) << (double) tot / r_size << "." << endl;

	int i = nums.size() / 2;

	if (nums.size() % 2 != 0) {
		cout << "Mediana: " << setprecision(3) << nums[i] << "." << endl;
	}
	else {
		int j = i-1;
		double mdn = ((double)nums[i] + nums[j])/2;
		cout << "Mediana: " << setprecision(3) << mdn << "." << endl;
	}

	unordered_map<int, int> occurrences;

	for (auto& n : nums) {
		occurrences[n]++;
	}

	vector<pair<int, int>> counts(occurrences.begin(), occurrences.end());
	sort(counts.begin(), counts.end(), comp);

	int md = counts[0].second;

	if (md == 1) {
		cout << "Il vettore non ha una moda." << endl;
		return 0;
	}

	cout << "Moda (" << md << " occorrenze): ";

	int j = 0;
	for (auto& p : counts) {
		if (p.second == md) {
			if (j > 0) cout << ", ";
			cout << p.first;
			j++;
		}
	}

	cout << "." << endl;
}

