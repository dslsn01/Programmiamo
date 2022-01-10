/* file Recursion.java */

public class Recursion {
	private static long factorial(int n) {
		if (n == 0 || n == 1) return 1;
		else return n * factorial(n - 1);
	}

	public static void main(String [] args) {
		String s = System.console().readLine("Inserisci un numero intero compreso tra zero e 20: ");

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		int n = Integer.parseInt(s);

		if (n > 20) {
			System.out.println("Numero fuori dell'intervallo!");
			return;
		}

		long fact = factorial(n);

		System.out.println(n + "! = " + fact);
	}
}

