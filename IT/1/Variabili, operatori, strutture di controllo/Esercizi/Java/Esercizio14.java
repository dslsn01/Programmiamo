/* file Esercizio14.java */

public class Esercizio14 {
	public static void main(String [] args) {
		int a = 100;

		System.out.print("Divisori di " + a + ": ");

		for (int i = 2; i < a; i++) {
			if (a % i == 0) {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());
	}
}

