/* file Esercizio25.java */

public class Esercizio25 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi un numero: ");

		// se non è un numero intero oppure in virgola mobile
		if (!s.matches("[\\d]+(\\.[\\d])?")) {
			System.out.println("Numero non valido!");
			return;
		}

		double x = Double.parseDouble(s);

		double xv = x >= 0 ? x : -x;

		System.out.println("Valore assoluto di " + x + " = " + xv);
	}
}

