/* file Esercizio16.java */

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio16 {
	public static void main(String [] args) {
		try {
			File doc = new File("file.txt");

			FileReader reader = new FileReader(doc);
			BufferedReader buffer = new BufferedReader(reader);

			for (int i = 0; i < 3; i++) {
				System.out.println(buffer.readLine());
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

