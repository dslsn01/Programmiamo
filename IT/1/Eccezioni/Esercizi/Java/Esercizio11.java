/* file Esercizio11.java */

public class Esercizio11 {
	public static void main(String [] args) {
		double c = 0;

		while (c == 0) {
			String s = System.console().readLine("Scrivi un numero: ");

			try {
				int n = Integer.parseInt(s);

				if (n == 0) {
					throw new IllegalArgumentException("Errore di dominio matematico: radice cubica di zero non definita");
				}

				c = Math.cbrt(n);
				System.out.println("Radice cubica di " + n + " = " + c);
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

