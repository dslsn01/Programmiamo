/*
file esercizio21.cpp
compilare con: g++ -std=c++11 esercizio21.cpp -lpthread
*/

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <iterator>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using std::copy;
using std::string;
using std::stoi;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ostream_iterator;
using std::thread;
using std::mutex;
using std::unique_lock;
using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::invalid_argument;
using std::move;

void sieve(vector<int> numbers, vector<int>& primes, mutex& _mutex) {
	for (int i = 0; i < numbers.size(); i++) {
		int n = numbers[i];
		bool isPrime = true;
		for (int j = 2; j < floor(sqrt(n))+1; j++) {
			if (n % j == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime == true) {
			unique_lock<mutex> lock(_mutex);
			primes.push_back(n);
		}
	}
}

int main() {
	long int n = 0;

	while (n < 2) {
		string tmp;
		cout << "Inserisci un numero naturale >= 2: ";
		getline(cin, tmp);
		try {
			n = stoi(tmp);
		}
		catch (invalid_argument&) {
			cerr << "Numero non valido!" << endl;
		}
	}

	const int N = n-1; // escludiamo 1 (non primo per definizione)

	int nThreads = n > 8 ? 4 : 1;
	int lSection = N / nThreads;
	if (N % nThreads > 0) nThreads++;

	int start = 0;
	int end = start + lSection;
	// const int SIZE = end-start;

	// int numbers[N];
	vector<int> numbers(N);
	for (int i = 0, j = 2; i < N; i++, j++) {
		numbers[i] = j;
	}

	mutex _mutex;
	vector<int> primes;

	thread workers[nThreads];

	auto startT = high_resolution_clock::now();

	for (int i = 0; i < nThreads; i++) {
		vector<int> tmp(end-start);
		tmp.assign(numbers.begin()+start, numbers.begin()+end);

		workers[i] = thread(sieve, move(tmp), ref(primes), ref(_mutex));

		start = end;
		if (start + lSection < N) {
			end = start + lSection;
		}
		else {
			end = N;
		}
	}

	for (auto& worker : workers) {
		worker.join();
	}

	auto endT = high_resolution_clock::now();

	// tempo totale in millisecondi
	duration<double> interval = endT - startT;
	microseconds tot = duration_cast<microseconds>(interval);
	double msecs = (double) tot.count() / 1000;

	cout << "Tempo totale: " << msecs << " millisecondi." << endl;

	int nPrimes = primes.size();
	cout << "Ci sono " << nPrimes << " numeri primi minori o uguali a " << n << "." << endl;

	if (nPrimes <= 100) {
		sort(primes.begin(), primes.end());
		copy(primes.begin(), primes.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

