/* file Esercizio26.java */

import java.io.Console;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio26 {
	public static void main(String [] args) {
		Console console = System.console();
		String filename = console.readLine("Apri il file: ");

		try {
			File doc = new File(filename);

			FileReader reader = new FileReader(doc);
			BufferedReader buffer = new BufferedReader(reader);

			String s = console.readLine("Parola da cercare: ");

			boolean found = false;
			int i = 1;

			while (buffer.ready()) {
				String line = buffer.readLine();
				if (line.toLowerCase().indexOf(s.toLowerCase()) != -1) {
					if (!found) found = true;
					System.out.println("La parola \"" + s + "\" compare alla riga " + i + ": \"" + line + "\"");
				}
				i++;
			}

			if (!found) {
				System.out.println("Parola \"" + s + "\" non trovata!");
			}

			buffer.close();
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

