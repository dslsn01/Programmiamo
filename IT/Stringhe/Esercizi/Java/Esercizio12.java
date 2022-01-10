/* file Esercizio12.java */

public class Esercizio12 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola (o una frase): ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		StringBuilder sb = new StringBuilder(s);
		String rev = sb.reverse().toString();

		System.out.println(rev);
	}
}

