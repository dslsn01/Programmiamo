/* file Esercizio22.java */

import java.io.Console;
import java.io.File;
import java.io.InputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Esercizio22 {
	public static void main(String [] args) {
		System.out.println("Confronto tra file");

		Console console = System.console();
		String filename1 = console.readLine("Primo file: ");
		File file1 = new File(filename1);

		String filename2 = console.readLine("Secondo file: ");
		File file2 = new File(filename2);

		if (file1.exists() && file2.exists()) {
			try
			{
				InputStream inputStream1 = Files.newInputStream(Paths.get(file1.toURI()));
				InputStream inputStream2 = Files.newInputStream(Paths.get(file2.toURI()));

				boolean comp = true;
				int file1Data;

				while ((file1Data = inputStream1.read()) != -1) {
					if (file1Data != inputStream2.read()) {
						comp = false;
						break;
					}
				}

				if (comp == true) {
					System.out.println("I file sono uguali.");
				}
				else {
					System.out.println("I file sono diversi!");
				}
			}
			catch (FileNotFoundException e) {
				System.out.println(e);
			}
			catch (IOException e) {
				System.out.println(e);
			}
		}
		else {
			System.out.println("Non trovo i file da confrontare!");
		}
	}
}

