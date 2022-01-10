/* file Esercizio18.java */

public class Esercizio18 {
	private static long factorial(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		else {
			return n * factorial(n - 1);
		}
	}

	public static void main(String [] args) {
		String s = System.console().readLine("Inserisci un numero intero compreso tra zero e 20: ");

		try {
			double d = Double.parseDouble(s);
			if (d < 0 || Math.floor(d) != d) {
				throw new IllegalArgumentException("Errore di dominio matematico: fattoriale definito solo per i numeri naturali!");
			}

			int n = (int)d;

			long fact = factorial(n);

			System.out.println(n + "! = " + fact);
		}
		catch (IllegalArgumentException e) {
			System.out.println(e.getMessage());
		}

		System.out.println("Fine del programma.");
	}
}

