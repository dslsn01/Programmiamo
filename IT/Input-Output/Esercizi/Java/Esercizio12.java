/* file Esercizio12.java */

import java.io.Console;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class Esercizio12 {
	public static void main(String [] args) {
		System.out.println("Scrivi una serie di parole. Invia la stringa vuota per uscire.");
		Console console = System.console();

		try {
			File doc = new File("file.txt");
			FileWriter writer = new FileWriter(doc);
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

