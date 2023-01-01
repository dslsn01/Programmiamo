/* file Esercizio13.java */

import java.io.Console;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class Esercizio13 {
	public static void main(String [] args) {
		System.out.println("Scrivi una serie di parole. Invia la stringa vuota per uscire.");

		Console console = System.console();
		String filename = console.readLine("File su cui scrivere: ");

		try {
			File doc = new File(filename);
			FileWriter writer = null;

			if (doc.exists()) {
				System.out.println("Il file esiste. Le modifiche saranno aggiunte al file esistente.");
				writer = new FileWriter(doc, true);
			}
			else {
				writer = new FileWriter(doc);
			}

			BufferedWriter buffer = new BufferedWriter(writer);

			while (true) {
				String s = console.readLine("Scrivi una parola: ");

				if (s.isEmpty()) {
					break;
				}

				buffer.write(s);
				buffer.write(System.lineSeparator());
			}

			buffer.close();

			System.out.println("File \"" + doc.getName() + "\" salvato su disco.");
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

