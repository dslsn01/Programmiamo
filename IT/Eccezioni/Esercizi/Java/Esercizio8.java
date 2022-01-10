/* file Esercizio8.java */

public class Esercizio8 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi un numero: ");

		try {
			int n = Integer.parseInt(s);
			System.out.println(n + " al quadrato = " + n * n);
		}
		catch (NumberFormatException e) {
			System.out.println(e.getMessage());
		}

		System.out.println("Fine del programma.");
	}
}

