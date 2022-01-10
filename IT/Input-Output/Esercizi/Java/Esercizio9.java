/* file Esercizio9.java */

import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Esercizio9 {
	public static void main(String [] args) {
		String filename = System.console().readLine("Apri il file: ");

		try {
			File f = new File(filename);

			if (f.exists()) {
				System.out.println("#### File esistente aperto in sola lettura. ####");
				FileReader fReader = new FileReader(f);
				BufferedReader bReader = new BufferedReader(fReader);

				while (bReader.ready()) {
					System.out.println(bReader.readLine());
				}

				bReader.close();
			}
			else {
				FileWriter fWriter = new FileWriter(f);
				BufferedWriter bWriter = new BufferedWriter(fWriter);
				Date date = new Date();
				SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
				bWriter.write("File creato il " + sdf.format(date) + System.lineSeparator());
				bWriter.close();
			}
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

