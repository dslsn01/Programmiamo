/* file ReadFile.java */

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile {
	public static void main(String [] args) {
		try {
			/* apre il file */

			File file1 = new File("helloworld.txt");
			FileReader reader = new FileReader(file1);
			BufferedReader input = new BufferedReader(reader);
		
			/* stampa il contenuto del file */

			while (input.ready()) {
				System.out.println(input.readLine());
			}

			/* chiude il file */

			reader.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

