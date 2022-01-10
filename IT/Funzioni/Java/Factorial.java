/* file Factorial.java */

public class Factorial {
	private static long factorial(int n) {
		long fact = 1;
		for (int i = 1; i <= n; i++) {
			fact *= i;
		}

		return fact;
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

