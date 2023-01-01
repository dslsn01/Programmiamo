/* file Esercizio19.java */

public class Esercizio19 {
	static boolean isPrime(int n) {
		if (n <= 1) return false;
		if (n == 1 || n == 3) return true;

		double sr = Math.sqrt(n);
		for (int i = 2; i <= (int)sr; i++) {
			if (n % i == 0) return false;
		}

		return true;
	}

	public static void main(String [] args) {
		for (int n = 2; n <= 100; n++) {
			if (isPrime(n) == true) System.out.print(n + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

