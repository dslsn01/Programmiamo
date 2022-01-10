/* file esercizio15.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	const int M = 10;
	const int N = 10;

	int i = 1;

	while (i <= M) {
		int j = 1;
		while (j <= N) {
			cout << (i * j) << "\t";
			j++;
		}
		i++;
		cout << endl;
	}
}

