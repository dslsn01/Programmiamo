/* file Esercizio16.java */

public class Esercizio16 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola (o una frase): ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		/* converte la parola o la frase in caratteri minuscoli */

		System.out.println(s.toLowerCase());
	}
}

