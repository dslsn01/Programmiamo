/* 
file listVsVector.cpp 
compilare con: g++ -std=c++11 listVsVector.cpp
*/

#include <iostream>
#include <list>
#include <vector>
#include <chrono>

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::milliseconds;
using std::chrono::steady_clock;

int main() {
	/* dichiara una lista linkata di interi */

	list<int> li;

	/* dichiara un vector di interi */

	vector<int> vect;

	for (int i = 0; i < 10000; i++) {
		li.push_back(i);
	}

	for (int i = 0; i < 10000; i++) {
		vect.push_back(i);
	}

	list<int>::iterator it1 = li.begin();

	/* tempo all'inizio dell'iterazione */

	steady_clock::time_point start = steady_clock::now();

	while (it1 != li.end()) {
		li.erase(it1++);
	}

	/* tempo alla fine dell'iterazione */

	steady_clock::time_point end = steady_clock::now();

	/* tempo complessivo per rimuovere tutti gli elementi della std::list con l'iteratore */

	unsigned long totalTime = duration_cast<microseconds>(end - start).count();

	cout << "Tempo per resettare una list: " << totalTime << " microsecondi." << endl;

	vector<int>::iterator it2 = vect.begin();

	start = steady_clock::now();

	while (it2 != vect.end()) {
		vect.erase(it2++);
	}

	end = steady_clock::now();

	/* tempo complessivo per rimuovere tutti gli elementi del vector con l'iteratore */

	totalTime = duration_cast<microseconds>(end - start).count();

	cout << "Tempo per resettare un vector: " << totalTime << " microsecondi." << endl;
}

