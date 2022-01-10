/* file Esercizio3.java */

public class Esercizio3 {
	public static void main(String [] args) {
		String s = "Ciao, mondo!";

		int sz = s.length();

		for (int i = 0; i < sz; i++) {
			System.out.print("(" + i + ") = '" + s.charAt(i) + "'");
			// aggiungo la virgola fino al penultimo carattere
			if (i < sz-1) {
				System.out.print(", ");
			}
		}

		System.out.print(System.lineSeparator());
	}
}

