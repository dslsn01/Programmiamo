/* file ex.cpp */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
	vector<int> sq(10);

	for (int i = 0, j = 1; i < sq.size(); i++, j++) {
		sq[i] = j*j;
	}

	cout << "[";
	copy(sq.begin(), sq.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

