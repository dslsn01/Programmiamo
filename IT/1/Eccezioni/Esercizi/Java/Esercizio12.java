/* file Esercizio12.java */

public class Esercizio12 {
	public static void main(String [] args) {
		double r = 0;

		while (r == 0) {
			String s = System.console().readLine("Scrivi un numero: ");

			try {
				int n = Integer.parseInt(s);

				if (n == 0) {
					throw new IllegalArgumentException("Errore di dominio matematico: reciproco di zero non definito");
				}

				r = (double)1/n;

				System.out.println("Reciproco di " + n + " = " + r);
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

