/* file Esercizio6.java */

public class Esercizio6 {
	public static void main(String [] args) {
		String s = "12345";
		int n = Integer.parseInt(s);

		if (n % 2 == 0) {
			System.out.println("Il numero " + s + " è pari.");
		}
		else {
			System.out.println("Il numero " + s + " è dispari.");
		}
	}
}

