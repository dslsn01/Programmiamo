/* file Esercizio27.java */

public class Esercizio27 {
	private static void forn(int n) {
		if (n > 0) {
			forn(n-1);
			System.out.print(n + " ");
		}
	}

	public static void main(String [] args) {
		forn(10);
		System.out.print(System.lineSeparator());
	}
}

