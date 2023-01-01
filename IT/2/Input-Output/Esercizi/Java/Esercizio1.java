/* file Esercizio1.java */

import java.io.File;

public class Esercizio1 {
	public static void main(String [] args) {
		File file = new File("file.txt");

		if (file.exists()) {
			System.out.println("Il file esiste.");
		}
		else {
			System.out.println("Il file non esiste!");
		}
	}
}

