/* file TestMatrix.java */

public class TestMatrix {
	public static void main(String [] args) {
		final int ROW = 5;
		final int COL = 5;
		int [][] matr = new int[ROW][COL];

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
				System.out.print(matr[i][j] + " ");
			}
			System.out.print(System.lineSeparator());
		}
	}
}

