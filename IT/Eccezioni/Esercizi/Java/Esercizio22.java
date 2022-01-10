/* file Esercizio22.java */

import java.io.Console;
import java.util.Arrays;

public class Esercizio22 {
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

			int index = -1;

			while (index < 0) {
				try {
					String animal = console.readLine("Quale animale vuoi recuperare? ");

					if (!Arrays.asList(animals).contains(animal)) {
						throw new IllegalArgumentException("Animale non presente nella lista!");
					}

					index = Arrays.asList(animals).indexOf(animal);
					System.out.println("L'animale \"" + animal + "\" si trova all'indice " + index + ".");
				}
				catch (IllegalArgumentException e) {
					System.out.println(e.getMessage());
				}
			}
		}
		catch (NumberFormatException e) {
			System.out.println(e.getMessage());
		}

		System.out.println("Fine del programma.");
	}
}

