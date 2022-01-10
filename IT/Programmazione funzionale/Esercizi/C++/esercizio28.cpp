/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::vector;

int rsum(vector<int>& v) {
	if (v.empty()) return 0;
	else {
		vector<int> subList(v.begin()+1, v.end());
		return v[0] + rsum(subList);
	}
}

int main() {
	vector<int> v(100);
	iota(v.begin(), v.end(), 1);
	cout << "Somma dei numeri da 1 a 100 = " << rsum(v) << endl;
}

