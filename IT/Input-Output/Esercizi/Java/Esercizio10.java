/* file Esercizio10.java */

import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Esercizio10 {
	public static void main(String [] args) {
		String filename = System.console().readLine("Apri il file: ");

		try {
			File f = new File(filename);
			FileWriter fWriter = null;
			String msg = "";
			Date date = new Date();
			SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");

			if (f.exists()) {
				fWriter = new FileWriter(f, true);
				msg = "File modificato il " + sdf.format(date) + System.lineSeparator();
			}
			else {
				fWriter = new FileWriter(f);
				msg = "File creato il " + sdf.format(date) + System.lineSeparator();
			}

			BufferedWriter bWriter = new BufferedWriter(fWriter);
			bWriter.write(msg);
			bWriter.close();
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

