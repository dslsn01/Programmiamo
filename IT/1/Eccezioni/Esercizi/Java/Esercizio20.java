/* file Esercizio20.java */

import java.io.Console;
import java.util.Arrays;

public class Esercizio20 {
	public static void main(String [] args) {
		Console console = System.console();
		String s = console.readLine("Quanti animali vuoi inserire? ");

		try {
			final int LEN = Integer.parseInt(s);

			if (LEN < 1) return;

			String [] animals = new String[LEN];
			int i = 0;

			while (i < LEN) {
				String animal = console.readLine("Scrivi un nuovo animale: ").toLowerCase();

				try {
					if (animal.isEmpty()) {
						throw new IllegalArgumentException("Nome non valido!");
					}
					if (Arrays.asList(animals).contains(animal)) {
						throw new IllegalArgumentException("Animale già presente!");
					}

					animals[i] = animal;
					i++;
				}
				catch (IllegalArgumentException e) {
					System.out.println(e.getMessage());
				}
			}

			System.out.println(Arrays.asList(animals));
		}
		catch (NumberFormatException e) {
			System.out.println(e.getMessage());
		}

		System.out.println("Fine del programma.");
	}
}

