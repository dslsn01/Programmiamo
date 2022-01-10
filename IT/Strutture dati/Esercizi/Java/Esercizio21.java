/* file Esercizio21.java */

public class Esercizio21 {
	public static void main(String [] args) {
		int [][] matrix = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};

		System.out.println("Matrice originale:");

		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[i].length; j++) {
				System.out.printf("%-2d", matrix[i][j]);
			}
			System.out.print(System.lineSeparator());
		}

		int sc = 3;

		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[i].length; j++) {
				matrix[i][j] *= sc;
			}
		}

		System.out.println("Matrice moltiplicata per lo scalare " + sc + ":");

		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[i].length; j++) {
				System.out.printf("%-3d", matrix[i][j]);
			}
			System.out.print(System.lineSeparator());
		}
	}
}

