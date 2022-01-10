/* file Esercizio18.java */

import java.io.Console;
import java.io.File;
import java.io.FileReader;
import java.io.LineNumberReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio18 {
	public static void main(String [] args) {
		LineNumberReader lReader = null;
		BufferedReader bReader = null;

		Console console = System.console();
		System.out.print("Apri il file: ");
		String fileName = console.readLine();

		try {
			File doc = new File(fileName);
			lReader = new LineNumberReader(new FileReader(doc));

			while (lReader.readLine() != null);
			int linecount = lReader.getLineNumber();

			bReader = new BufferedReader(new FileReader(doc));

			if (linecount <= 10) {
				while (bReader.ready()) {
					System.out.println(bReader.readLine());
				}
			}
			else {
				for (int i = 0; i < (linecount - 10); i++) {
					bReader.readLine();
				}

				while (bReader.ready()) {
					System.out.println(bReader.readLine());
				}
			}

			lReader.close();
			bReader.close();
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

