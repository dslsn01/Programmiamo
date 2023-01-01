/* file Esercizio23.java */

public class Esercizio23 {
	public static void main(String [] args) {
		final int M = 3;
		final int N = 3;
		int [][] matrix1 = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
		int [][] matrix2 = {{2, 9, 1}, {4, 6, 3}, {5, 7, 1}};
		int [][] p = new int[M][N];

		System.out.println("Prima matrice:");

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				System.out.printf("%-2d", matrix1[i][j]);
			}
			System.out.print(System.lineSeparator());
		}

		System.out.println("Seconda matrice:");

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				System.out.printf("%-2d", matrix2[i][j]);
			}
			System.out.print(System.lineSeparator());
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					p[i][j] += matrix1[i][k] + matrix2[k][j];
				}
			}
		}

		System.out.println("Prodotto di matrici:");

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				System.out.printf("%-3d", p[i][j]);
			}
			System.out.print(System.lineSeparator());
		}
	}
}

