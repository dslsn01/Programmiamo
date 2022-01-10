/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp
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
using std::copy;
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

	copy(nums, nums+LEN, ostream_iterator<int>(cout, " "));
	cout << endl;

	int tot = 0;

	for (int i = 0; i < LEN; i++) {
		tot += nums[i];
	}

	double med = (double) tot / LEN;

	cout << "Media: " << setprecision(3) << med << "." << endl;

	double mdn = 0;

	if (LEN % 2 != 0) {
		int i = LEN / 2;
		mdn = nums[i];
	}
	else {
		int i = LEN / 2;
		int j = i-1;
		mdn = (double)(nums[i] + nums[j])/2;
	}

	cout << "Mediana: " << setprecision(3) << mdn << "." << endl;

	int md = 1;
	int counts[LEN];
	int i = 0;

	while (i < LEN) {
		int n = nums[i];
		int j = i+1; // indice dell'elemento successivo
		int occ = 1;
		while (j < LEN && n == nums[j]) {
			occ++;
			j++;
		}
		counts[i] = occ; // memorizza il numero di occorrenze
		if (occ > md) md = occ;
		i += occ; // salta al prossimo numero
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
			cout << nums[i];
			j++;
		}
	}

	cout << "." << endl;

	delete [] nums;
}

