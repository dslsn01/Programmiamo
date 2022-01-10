/* file Esercizio11.java */

import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class Esercizio11 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola o una frase: ");

		try {
			File doc = new File("file.txt");
			FileWriter writer = new FileWriter(doc);
			BufferedWriter buffer = new BufferedWriter(writer);

			buffer.write(s);
			buffer.write(System.lineSeparator());
			buffer.close();

			System.out.println("File \"" + doc.getName() + "\" salvato su disco.");
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

