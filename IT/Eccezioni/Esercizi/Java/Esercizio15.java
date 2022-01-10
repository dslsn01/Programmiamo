/* file Esercizio15.java */

public class Esercizio15 {
	public static void main(String [] args) {
		System.out.println("Pari o dispari?");

		try {
			String s = System.console().readLine("Scrivi un numero: ");
			double d = Double.parseDouble(s);

			if (!(d == Math.floor(d))) {
				throw new IllegalArgumentException("Errore di dominio matematico: la distinzione tra \"pari\" o \"dispari\" vale solo per i numeri interi!");
			}

			int n = (int)d;
			if (n % 2 == 0) {
				System.out.println(n + " è pari!");
			}
			else {
				System.out.println(n + " è dispari!");
			}
		}
		catch (IllegalArgumentException e) {
			System.out.println(e.getMessage());
		}

		System.out.println("Fine del programma.");
	}
}

