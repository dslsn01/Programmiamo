/* file Esercizio22.java */

public class Esercizio22 {
	public static void main(String [] args) {
		int [][] matrix1 = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
		int [][] matrix2 = {{2, 9, 1}, {4, 6, 3}, {5, 7, 1}};

		System.out.println("Prima matrice:");

		for (int i = 0; i < matrix1.length; i++) {
			for (int j = 0; j < matrix1[i].length; j++) {
				System.out.printf("%-2d", matrix1[i][j]);
			}
			System.out.print(System.lineSeparator());
		}

		System.out.println("Seconda matrice:");

		for (int i = 0; i < matrix2.length; i++) {
			for (int j = 0; j < matrix2[i].length; j++) {
				System.out.printf("%-2d", matrix2[i][j]);
			}
			System.out.print(System.lineSeparator());
		}

		for (int i = 0; i < matrix2.length; i++) {
			for (int j = 0; j < matrix2[i].length; j++) {
				matrix2[i][j] += matrix1[i][j];
			}
		}

		System.out.println("Somma delle matrici:");

		for (int i = 0; i < matrix2.length; i++) {
			for (int j = 0; j < matrix2[i].length; j++) {
				System.out.printf("%-3d", matrix2[i][j]);
			}
			System.out.print(System.lineSeparator());
		}
	}
}

