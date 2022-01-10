/* file Esercizio4.java */

public class Esercizio4 {
	public static void main(String [] args) {
		String s = "Ciao, mondo!";

		for (int i = s.length() - 1; i >= 0; i--) {
			System.out.print(s.charAt(i));
		}

		System.out.print(System.lineSeparator());
	}
}

