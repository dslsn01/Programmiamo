/* file Esercizio29.java */

import java.io.Console;

public class Esercizio29 {
	public static void main(String [] args) {
		Console console = System.console();

		String l = console.readLine("Quanti numeri vuoi inserire? ");

		if (!l.matches("[\\d]+")) {
				System.out.println("Numero non valido!");
				return;
		}

		int limit = Integer.parseInt(l);

		int i = 0;
		int x = 0;

		while (i < limit) {
			String s = console.readLine("Numero corrente: ");

			if (!s.matches("[\\d]+")) {
				System.out.println("Numero non valido!");
				continue;
			}

			int n = Integer.parseInt(s);

			if (n > x) {
				x = n;
			}
			i++;
		}

		System.out.println("Il numero più grande è " + x + ".");
	}
}

