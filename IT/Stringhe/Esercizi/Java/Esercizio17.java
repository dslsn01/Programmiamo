/* file Esercizio17.java */

public class Esercizio17 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola (o una frase): ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		StringBuilder result = new StringBuilder();

		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);

			/* la classe Character è un wrapper per il tipo primitivo 'char'*/
			if (i % 2 == 0) result.append(Character.toUpperCase(c));
			else result.append(Character.toLowerCase(c));
		}

		System.out.println(result);
	}
}

