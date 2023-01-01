/* file Esercizio20.java */

import java.util.List;
import java.io.Console;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.charset.Charset;

public class Esercizio20 {
	public static void main(String [] args) {
		Console console = System.console();
		String filename = console.readLine("File da copiare: ");

		try {
			File doc = new File(filename);

			String bakName = console.readLine("Nome file di backup: ");
			File backup = new File(bakName);

			if (backup.exists()) {
				String opt = console.readLine("Il file \"" + bakName + "\" esiste. Sovrascriverlo? s | n: ");

				if (!opt.toLowerCase().equals("s")) {
					System.out.println("File \"" + bakName + "\" ignorato.");
					return;
				}
			}

			BufferedWriter buffer = new BufferedWriter(new FileWriter(backup));

			List<String> lines = Files.readAllLines(Paths.get(doc.toURI()), Charset.defaultCharset());

			for (String line : lines) {
				buffer.write(line);
				buffer.write(System.lineSeparator());
			}

			buffer.close();

			System.out.println("File \"" + backup.getName() + "\" salvato su disco.");
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

