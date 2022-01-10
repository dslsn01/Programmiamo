/* file Esercizio8.java */

import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Esercizio8 {
	public static void main(String [] args) {
		String filename = System.console().readLine("Apri il file: ");

		try {
			File f = new File(filename);
			FileWriter fWriter = new FileWriter(f);
			BufferedWriter bWriter = new BufferedWriter(fWriter);

			Date date = new Date();
			SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");

			bWriter.write("File creato il " + sdf.format(date) + System.lineSeparator());
			bWriter.close();
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}

