/* file Esercizio6.java */

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Stack;

public class Esercizio6 {
	public static void main(String [] args) {
		String filename = System.console().readLine("Apri il file: ");

		try {
			File f = new File(filename);
			FileReader fReader = new FileReader(f);
			BufferedReader bReader = new BufferedReader(fReader);

			Stack<String> lines = new Stack<>();

			while (bReader.ready()) {
				lines.add(bReader.readLine());
			}

			for (int i = lines.size(); i >= 1; i--) {
				System.out.println(i + " " + lines.pop());
			}

			bReader.close();
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}

