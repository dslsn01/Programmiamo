/* file Esercizio21.java */

import java.io.Console;
import java.util.Arrays;

public class Esercizio21 {
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

			String animal = "";

			while (animal.isEmpty()) {
				try {
					String pos = console.readLine("Recupera l'animale con indice: ");
					int index = Integer.parseInt(pos);

					animal = animals[index];
					System.out.println(animal);
				}
				catch (NumberFormatException e) {}
				catch (ArrayIndexOutOfBoundsException e) {
					System.out.println("Animale non presente nella lista! ");
				}
			}
		}
		catch (NumberFormatException e) {
			System.out.println(e.getMessage());
		}

		System.out.println("Fine del programma.");
	}
}

