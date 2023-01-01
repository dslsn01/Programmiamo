/* file Esercizio20.java */

public class Esercizio20 {
	public static void main(String [] args) {
		final int M = 3;
		final int N = 3;
		int [][] matrix = new int[M][N];

		int k = M * N;
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[i].length; j++) {
				matrix[i][j] = k;
				k--;
			}
		}

		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[i].length; j++) {
				System.out.printf("%-2d", matrix[i][j]);
			}
			System.out.print(System.lineSeparator());
		}
	}
}

