/* file Esercizio24.java */

import java.io.Console;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio24 {
	public static void main(String [] args) {
		Console console = System.console();
		String filename = console.readLine("Apri il file: ");

		try {
			File doc = new File(filename);

			FileReader reader = new FileReader(doc);
			BufferedReader buffer = new BufferedReader(reader);

			String s = console.readLine("Parola da cercare: ");

			int counter = 0;

			while (buffer.ready()) {
				String line = buffer.readLine().toLowerCase();
				int pos = 0;
				while ((pos = line.indexOf(s.toLowerCase(), pos)) != -1) {
					counter++;
					pos++;
				}
			}

			if (counter != 0) {
				System.out.println("La parola \"" + s + "\" compare " + counter + " volte nel file.");
			}
			else {
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

