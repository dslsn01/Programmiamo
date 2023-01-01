/* file Esercizio10.java */

public class Esercizio10 {
	public static void main(String [] args) {
		double sq = -1;

		while (sq < 0) {
			String s = System.console().readLine("Scrivi un numero: ");

			try {
				int n = Integer.parseInt(s);

				if (n < 0) {
					throw new IllegalArgumentException("Errore di dominio matematico: radice quadrata indefinita per i numeri negativi");
				}

				sq = Math.sqrt(n);
				System.out.println("Radice quadrata di " + n + " = " + sq);
			}
			catch (NumberFormatException e) {
				System.out.println(e.getMessage());
			}
			catch (IllegalArgumentException e) {
				System.out.println(e.getMessage());
			}
		}

		System.out.println("Fine del programma.");
	}
}

