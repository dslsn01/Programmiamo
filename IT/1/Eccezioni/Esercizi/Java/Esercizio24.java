/* file Esercizio24.java */

import java.util.Calendar;
import java.io.Console;

public class Esercizio24 {
	public static void main(String [] args) {
		boolean checked = false;
		String user = "";
		int age = -1;
		Console console = System.console();

		while (checked == false) {
			try {
				if (user.isEmpty()) {
					user = console.readLine("Scrivi il tuo nome: ");

					if (user.isEmpty()) {
						throw new IllegalArgumentException("Nome non valido!");
					}
				}

				if (age < 0) {
					String strYear = console.readLine("Il tuo anno di nascita: ");

					int year = Integer.parseInt(strYear);
					int currYear = Calendar.getInstance().get(Calendar.YEAR);

					if (year <= 0 || year > currYear) {
						throw new IllegalArgumentException("Anno di nascita non valido!");
					}

					age = currYear - year;
				}

				System.out.println("Ciao, " + user + "! Hai " + age + " anni.");
				checked = true;
			}
			catch (NumberFormatException e) {
				System.out.println(e.getMessage());
			}
			catch (IllegalArgumentException e) {
				System.out.println(e.getMessage());
			}
		}

		System.out.println("Fine del programma.");
	}
}

