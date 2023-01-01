/* file Esercizio7.java */

import java.io.RandomAccessFile;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Esercizio7 {
	public static void main(String [] args) {
		String filename = System.console().readLine("Apri il file: ");

		try {
			RandomAccessFile f = new RandomAccessFile(filename, "r");

			while (f.getFilePointer() < f.length()) {
				System.out.println(f.readLine());
			}

			System.out.println("-> torna alla prima riga.");

			f.seek(0);

			while (f.getFilePointer() < f.length()) {
				System.out.println(f.readLine());
			}

			f.close();
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}

