/* file Esercizio9.java */

public class Esercizio9 {
	public static void main(String [] args) {
		int square = 0;

		while (square == 0) {
			String s = System.console().readLine("Scrivi un numero: ");

			try {
				int n = Integer.parseInt(s);
				square = n * n;
				System.out.println(n + " al quadrato = " + square);
			}
			catch (NumberFormatException e) {
				System.out.println(e.getMessage());
			}
		}

		System.out.println("Fine del programma.");
	}
}

