/* file Esercizio23.java */

public class Esercizio23 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi un numero: ");

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		int n = Integer.parseInt(s);

		int c = n * n * n;

		System.out.println(n + " al cubo = " + c);
	}
}

