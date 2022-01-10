/* file Esercizio5.java */

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio5 {
	public static void main(String [] args) {
		String filename = System.console().readLine("Apri il file: ");

		try {
			File f = new File(filename);
			FileReader fReader = new FileReader(f);
			BufferedReader bReader = new BufferedReader(fReader);

			int i = 1;
			while (bReader.ready()) {
				System.out.println(i + " " + bReader.readLine());
				i++;
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

