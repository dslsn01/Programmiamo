/* file Esercizio22.java */

public class Esercizio22 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi un numero: ");

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		int n = Integer.parseInt(s);

		int q = n * n;

		System.out.println(n + " al quadrato = " + q);
	}
}

