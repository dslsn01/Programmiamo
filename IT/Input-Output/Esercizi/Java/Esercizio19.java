/* file Esercizio19.java */

import java.util.List;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.charset.Charset;

public class Esercizio19 {
	public static void main(String [] args) {
		String filename = System.console().readLine("File da copiare: ");

		try {
			File doc = new File(filename);

			String bakName = doc.getName() + ".bak";

			File backup = new File(bakName);
			FileWriter writer = new FileWriter(backup);
			BufferedWriter buffer = new BufferedWriter(writer);

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

