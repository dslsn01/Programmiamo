/* file Esercizio13.java */

public class Esercizio13 {
	public static void main(String [] args) {
		double l = -1;

		while (l < 0) {
			String s = System.console().readLine("Scrivi un numero: ");

			try {
				int n = Integer.parseInt(s);

				if (n <= 0) {
					throw new IllegalArgumentException("Errore di dominio matematico: logaritmo non definito per n <= 0");
				}

				l = Math.log(n);
				System.out.println("Logaritmo di " + n + " = " + l);
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

