/* file Esercizio29.java */

import java.util.Scanner;
import java.io.Console;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class Esercizio29 {
	public static void main(String [] args) throws Exception {
		System.out.println("Un semplice editor di testo\nPremi \"Ctrl+C\" (su Windows) o \"Ctrl+D\" (Linux e MacOS) per finire di scrivere.\n");

		String filename = "";
		File doc = null;
		if (args.length > 0) {
			filename = args[0];
			doc = new File(filename);
			if (doc.exists()) {
				BufferedReader rdr = new BufferedReader(new FileReader(doc));
				while (rdr.ready()) {
					System.out.println(rdr.readLine());
				}
			}
		}

		Scanner scanner = new Scanner(System.in);
		StringBuilder text = new StringBuilder();

		while (scanner.hasNextLine()) {
			String token = scanner.nextLine();
			text.append(token + System.lineSeparator());
		}

		boolean quit = false;
		boolean app = false;
		Console console = System.console();

		while (!quit) {
			String buff = console.readLine("Digita \"s\" per salvare su file, \"q\" per uscire senza salvare: ");

			if (buff.length() > 1) continue;
			char opt = Character.toLowerCase(buff.charAt(0));

			if (opt == 's') {
				boolean save = doc == null ? false : true;
				app = save;

				while (!save) {
					filename = console.readLine("Salva con nome: ");
					doc = new File(filename);

					if (doc.exists()) {
						String buf2 = System.console().readLine("Il file \"" + filename + "\" esiste. Sovrascriverlo? \"y\" - si, \"n\" - no: ");
						char ow = Character.toLowerCase(buf2.charAt(0));
						if (ow == 'y') save = true;
					}
					else {
						save = true;
					}
				}

				try {
					FileWriter writer = new FileWriter(doc, app);
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

