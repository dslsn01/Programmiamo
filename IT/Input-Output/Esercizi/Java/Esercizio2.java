/* file Esercizio2.java */

import java.io.File;
import java.io.FileReader;
import java.io.FileNotFoundException;

public class Esercizio2 {
	public static void main(String [] args) {
		try {
			File f = new File("file.txt");
			FileReader fReader = new FileReader(f);
			System.out.println(fReader);
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
	}
}

