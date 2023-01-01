/* file Esercizio15.java */

public class Esercizio15 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola (o una frase): ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		/* converte la parola o la frase in caratteri maiuscoli */

		System.out.println(s.toUpperCase());
	}
}

