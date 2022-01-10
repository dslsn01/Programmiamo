/* file Esercizio17.java */

public class Esercizio17 {
	public static void main(String [] args) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				if (i == j) {
					System.out.print(i);
				}
				else {
					System.out.print(" ");
				}
			}

			System.out.print(System.lineSeparator());
		}
	}
}

