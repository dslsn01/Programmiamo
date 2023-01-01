/* 
file sorting.cpp 
compilare con: g++ -std=c++11 sorting.cpp
*/

#include <iostream>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;

int main()
{
	/* dichiara un array di interi casuali */

	const int LEN = 10;
	int arr[LEN];

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < LEN; i++) {
		arr[i] = dist(gen);
	}

	cout << "Array originale: " << endl;

	for (int& n : arr) {
		cout << n << " ";
	}

	cout << endl;

	/* ordina gli elementi dell'array */

	sort(begin(arr), end(arr));

	cout << "Array ordinato: " << endl;

	for (int& n : arr) {
		cout << n << " ";
	}

	cout << endl;
}

