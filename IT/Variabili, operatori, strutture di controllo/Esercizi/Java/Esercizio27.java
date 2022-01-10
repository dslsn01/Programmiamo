/* file Esercizio27.java */

public class Esercizio27 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi un numero: ");

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		int n = Integer.parseInt(s);

		if (n > 0) {
			System.out.println(n + " è positivo.");
		}
		else {
			if (n == 0) {
				System.out.println("Hai digitato zero!");
			}
			else {
				System.out.println(n + " è negativo.");
			}
		}
	}
}

