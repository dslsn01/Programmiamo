/* file esercizio20.cpp */

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::left;
using std::setw;

int main()
{
	const int M = 3;
	const int N = 3;
	int matrix[M][N];

	int k = M * N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = k;
			k--;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << left << setw(2) << matrix[i][j];
		}
		cout << endl;
	}
}

