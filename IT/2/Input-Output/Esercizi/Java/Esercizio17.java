/* file Esercizio17.java */

import java.util.List;
import java.io.File;
import java.io.IOException;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.charset.Charset;

public class Esercizio17 {
	public static void main(String [] args) {
		try {
			File doc = new File("file.txt");

			List<String> lines = Files.readAllLines(Paths.get(doc.toURI()), Charset.defaultCharset());

			int j = lines.size();

			for (int i = j - 3; i < j; i++) {
				System.out.println(lines.get(i));
			}
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}

