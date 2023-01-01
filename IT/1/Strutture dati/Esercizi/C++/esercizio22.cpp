/* file esercizio19.cpp */

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
	int matrix1[M][N] = {{1, 4, 0}, {0, 3, 2}, {4, 6, 9}};
	int matrix2[M][N] = {{2, 9, 1}, {4, 6, 3}, {5, 7, 1}};

	cout << "Prima matrice: " << endl;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << left << setw(2) << matrix1[i][j];
		}
		cout << endl;
	}

	cout << "Seconda matrice: " << endl;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << left << setw(2) << matrix2[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix2[i][j] += matrix1[i][j];
		}
	}

	cout << "Somma delle matrici: " << endl;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << left << setw(3) << matrix2[i][j];
		}
		cout << endl;
	}
}

