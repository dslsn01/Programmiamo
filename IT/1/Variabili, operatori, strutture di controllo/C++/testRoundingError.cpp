/* file testRoundingError.cpp */

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;

int main() {
	double x = 0.1;
	double y = 1.0;

	for (int i = 1; i < 10; i++) {
		cout << setprecision(16) << x << endl;
		x += 0.1;
	}

	if (x == y) {
		cout << x << " e " << y << " sono uguali!" << endl;
	}
	else {
		cout << x << " e " << y << " sono diversi!" << endl;
	}
}

