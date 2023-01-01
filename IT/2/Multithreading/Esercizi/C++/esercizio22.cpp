/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp -lpthread
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <vector>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::set;
using std::vector;
using std::thread;
using std::mutex;

void powerset(set<int>& _set, int start, int end, set<set<int>>& powerSet, mutex& _mutex) {
	// serve proprio? Probabilmente sì, per avere l'accesso posizionale
	vector<int> bits;
	bits.reserve(_set.size());
	copy(_set.begin(), _set.end(), back_inserter(bits));

	for (int i = start; i < end; i++) {
		set<int> subSet;
		for (int j = 0; j < bits.size(); j++) {
			int mask = 1 << j;
			if ((i & mask) != 0) {
				cout << bits[j] << " ";
				// subSet.insert(bits[j]);
			}
		}

		// usare uno std::lock_guard? Quali sono i pro e i contro?
		_mutex.lock();
		powerSet.insert(subSet);
		_mutex.unlock();
	}
}

int main() {
	set<int> _set = {1, 2, 3};

	// cout << "{";
	copy(_set.begin(), _set.end(), ostream_iterator<int>(cout, " "));
	// cout << "}";
	cout << endl;

	const int CARD_PSET = 1 << _set.size(); // 2^n
	cout << "Cardinalità dell'insieme potenza: " << CARD_PSET << endl;

	int nThreads = 1; // CARD_PSET / 2; // 4 threads

	int start = 0;
	int end = CARD_PSET / nThreads;

	mutex _mutex;
	set<set<int>> powerSet;

	thread threads[nThreads];

	for (int i = 0, j = 2; i < nThreads; i++, j++) {
		threads[i] = thread(powerset, ref(_set), start, end, ref(powerSet), ref(_mutex));

		start = end;
		end = j * (CARD_PSET / nThreads);
	}

	for (auto& thread : threads) {
		thread.join();
	}

	cout << endl;

	// cout << "Cardinalità insieme potenza: " << powerSet.size() << endl;
	cout << "Insieme potenza: " << endl;

	// for (auto it = powerSet.begin(); it != powerSet.end(); ++it) {
	cout << "{";

	int i = 0;
	for (auto& subSet : powerSet) {
		// set<int> subSet = (*it);
		cout << "{";
		int j = 0;
		for (auto& elem : subSet) {
			cout << elem;
			if (j < subSet.size() - 1) {
				cout << ", ";
			}
			j++;
		}
		// copy(subSet.begin(), subSet.end(), ostream_iterator<int>(cout, " "));
		cout << "}";
		if (i < powerSet.size() - 1) {
			cout << ", ";
		}
		i++;
	}

	cout << "}" << endl;
}

