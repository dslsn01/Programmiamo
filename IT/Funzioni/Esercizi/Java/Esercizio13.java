/* file Esercizio13.java */

public class Esercizio13 {
	static int square(int n) {
		return n * n;
	}

	public static void main(String [] args) {
		for (int n = 1; n <= 10; n++) {
			System.out.println(n + " al quadrato = " + square(n));
		}
	}
}

