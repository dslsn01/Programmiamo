/* file Esercizio24.java */

public class Esercizio24 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi un numero: ");

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		int n = Integer.parseInt(s);

		int ex = 2;

		while (ex <= 10) {
			System.out.println("Potenza di " + n + " elevato a " + ex + " = " + Math.pow(n, ex));
			ex++;
		}
	}
}

