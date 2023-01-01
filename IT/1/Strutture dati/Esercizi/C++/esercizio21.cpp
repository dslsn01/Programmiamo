/* file esercizio21.cpp */

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
	int matrix[M][N] = {{1, 4, 0}, {0, 3, 2}, {4, 6, 9}};

	cout << "Matrice originale: " << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << left << setw(2) << matrix[i][j];
		}
		cout << endl;
	}

	int sc = 3;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] *= sc;
		}
	}

	cout << "Matrice moltiplicata per lo scalare " << sc << ": " << endl;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << left << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
}

