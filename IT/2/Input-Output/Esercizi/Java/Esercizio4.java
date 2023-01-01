/* file Esercizio4.java */

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio4 {
	public static void main(String [] args) {
		String filename = System.console().readLine("Apri il file: ");

		try {
			File f = new File(filename);
			FileReader fReader = new FileReader(f);
			BufferedReader bReader = new BufferedReader(fReader);

			while (bReader.ready()) {
				System.out.println(bReader.readLine());
			}

			bReader.close();
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}

