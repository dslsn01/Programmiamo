/* file Esercizio15.java */

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio15 {
	public static void main(String [] args) {
		try {
			File doc = new File("file.txt");

			FileReader reader = new FileReader(doc);
			BufferedReader buffer = new BufferedReader(reader);

			while (buffer.ready()) {
				String word = buffer.readLine();
				System.out.print(word.replaceAll(System.lineSeparator(), "") + " ");
			}

			System.out.print(System.lineSeparator());

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

