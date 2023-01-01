/* file Esercizio11.java */

public class Esercizio11 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola (o una frase): ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		int sz = s.length();
		int ch = 0;
		int num = 0;
		int sp = 0;

		char [] arr = s.toCharArray();

		for (char c : arr) {
			if (Character.isLetter(c)) ch++;
			else if (Character.isDigit(c)) num++;
			else sp++;
		}

		System.out.println("La stringa \"" + s + "\" (" + sz + " caratteri totali) contiene " + ch + " lettere, " + num + " numeri e " + sp + " simboli.");
	}
}

