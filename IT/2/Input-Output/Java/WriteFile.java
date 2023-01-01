/* file WriteFile.java */

import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class WriteFile {
	public static void main(String [] args) {
		try {
			/* apre il file */

			File file1 = new File("helloworld.txt");
			FileWriter writer = new FileWriter(file1);
			BufferedWriter output = new BufferedWriter(writer);

			/* scrive nel file la frase "Ciao, mondo!" */

			output.write("Ciao, mondo!");

			/* chiude il file e salva le modifiche */

			output.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

