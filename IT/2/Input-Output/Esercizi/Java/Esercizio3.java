/* file Esercizio3.java */

import java.io.File;
import java.io.FileReader;
import java.io.FileNotFoundException;

public class Esercizio3 {
	public static void main(String [] args) {
		String filename = System.console().readLine("Apri il file: ");

		try {
			File f = new File(filename);
			FileReader fReader = new FileReader(f);
			System.out.println(fReader);
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
	}
}

