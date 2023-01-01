/* file Esercizio31.java */

import java.io.Console;

public class Esercizio31 {
	public static void main(String [] args) {
		Console console = System.console();

		String l = console.readLine("Quanti numeri vuoi inserire? ");

		if (!l.matches("[\\d]+")) {
				System.out.println("Numero non valido!");
				return;
		}

		int limit = Integer.parseInt(l);

		int i = 0;
		int tot = 0;

		while (i < limit) {
			String s = console.readLine("Numero corrente: ");

			if (!s.matches("[\\d]+")) {
				System.out.println("Numero non valido!");
				continue;
			}

			int n = Integer.parseInt(s);

			tot += n;
			i++;
		}

		System.out.println("La media di tutti i numeri è " + (double) tot / limit + ".");
	}
}

