/* file Esercizio14.java */

public class Esercizio14 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola o numero: ");

		try {
			int n = Integer.parseInt(s);
			System.out.println(s + " è un numero intero.");
		}
		catch (NumberFormatException e1) {
			System.out.println(e1.getMessage());
			try {
				double d = Double.parseDouble(s);
				System.out.println(s + " è un numero in virgola mobile.");
			}
			catch (NumberFormatException e2) {
				System.out.println(e2.getMessage());
				System.out.println("\"" + s + "\" non può essere convertito in un numero.");
			}
		}
	}
}

