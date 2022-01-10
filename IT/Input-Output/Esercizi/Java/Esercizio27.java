/* file Esercizio27.java */

import java.util.Scanner;
import java.io.Console;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class Esercizio27 {
	public static void main(String [] args) throws Exception {
		System.out.println("Un semplice editor di testo\nPremi \"Ctrl+C\" (su Windows) o \"Ctrl+D\" (Linux e MacOS) per finire di scrivere.\n");

		String filename = "";
		Scanner scanner = new Scanner(System.in);
		StringBuilder text = new StringBuilder();

		while (scanner.hasNextLine()) {
			String token = scanner.nextLine();
			text.append(token + System.lineSeparator());
		}

		boolean quit = false;
		Console console = System.console();

		while (!quit) {
			String buff = console.readLine("Digita \"s\" per salvare su file, \"q\" per uscire senza salvare: ");

			if (buff.length() > 1) continue;
			char opt = Character.toLowerCase(buff.charAt(0));

			if (opt == 's') {
				filename = console.readLine("Salva con nome: ");

				try {
					File doc = new File(filename);
					FileWriter writer = new FileWriter(doc);
					BufferedWriter buffer = new BufferedWriter(writer);

					String [] lines = text.toString().split(System.lineSeparator());

					for (String line : lines) {
						buffer.write(line + System.lineSeparator());
					}

					buffer.close();

					System.out.println("File \"" + doc.getName() + "\" salvato su disco.");
					quit = true;
				}
				catch (IOException e) {
					e.printStackTrace();
				}
				/*
				finally {
					scanner.close();
				}
				*/
			}
			else if (opt == 'q') {
				quit = true;
			}
		}
	}
}

