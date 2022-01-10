/* file Esercizio14.java */

import java.io.File;
import java.io.FileReader;
import java.io.LineNumberReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio14 {
	public static void main(String [] args) {
		try {
			File doc = new File("file.txt");

			FileReader reader = new FileReader(doc);
			LineNumberReader lReader = new LineNumberReader(reader);

			while (lReader.readLine() != null);
			int linecount = lReader.getLineNumber();

			lReader.close();

			System.out.println("Il file \"" + doc.getName() + "\" contiene " + linecount + " righe.");
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

