/*
file esercizio9.cpp
compilare con: g++ -std=c++11 esercizio9.cpp -lpthread
*/

#include <iostream>
#include <list>
#include <iterator>
#include <future>

using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::list;
using std::ostream_iterator;
using std::async;
using std::future;

int* func(int index) {
	int* row = new int[10];

	for (int i = 0; i < 10; i++) {
		row[i] = index;
	}

	for (int index = 0, k = 1;  index < 10; index++, k++) {
		row[index] *= k;
	}

	return row;
}

int main()
{
	int nThreads = 10;

	list<future<int*>> tbp;

	for (int i = 1; i <= nThreads; i++) {
		tbp.push_back(async(std::launch::async, func, i));
	}

	for (auto it = tbp.begin(); it != tbp.end(); ++it) {
		int *row = (*it).get();
		copy(row, row+10, ostream_iterator<int>(cout, " "));
		cout << endl;
		delete row;
	}
}

