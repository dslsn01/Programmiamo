/* file CopyFile.java */

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class CopyFile {
	public static void main(String [] args) {
		try {
			/* apre il primo file */

			File file1 = new File("helloworld.txt");
			FileReader reader = new FileReader(file1);
			BufferedReader input = new BufferedReader(reader);

			/* apre il secondo file */

			File file2 = new File("helloworld2.txt");
			FileWriter writer = new FileWriter(file2);
			BufferedWriter output = new BufferedWriter(writer);

			/* copia il contenuto del primo file nel secondo */

			while (input.ready()) {
				output.write(input.readLine());
			}
		
			/* chiude entrambi i file */
	
			input.close();
			output.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

