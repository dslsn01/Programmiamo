/* file testMatrix.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	const int ROW = 5;
	const int COL = 5;
	int matr[ROW][COL] = {};

	// inizializza una matrice di 5 righe * 5 colonne

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (i == j) {
				matr[i][j] = 1;
			}
		}
	}

	// stampa la matrice

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}

