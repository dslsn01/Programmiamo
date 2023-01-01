/* file Esercizio26.java */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio26 {
	public static void main(String [] args) {
		String s = "Nel mezzo del cammin di nostra vita" + System.lineSeparator();
		s += "mi ritrovai per una selva oscura" + System.lineSeparator();
		s += "chè la retta via era smarrita.";

		System.out.println("\"" + s + "\"");

		// contatore delle righe
		int rCount = 0;

		Pattern pattern = Pattern.compile("([^\r\n]+)");
		Matcher matcher = pattern.matcher(s);

		while (matcher.find()) rCount++;

		// contatore delle parole
		int wCount = 0;

		pattern = Pattern.compile("([a-zA-ZÀ-ù']+)");
		matcher = pattern.matcher(s);

		while (matcher.find()) wCount++;

		// contatore delle frasi
		int sCount = 0;

		pattern = Pattern.compile("(.*[\\.\r\n])");
		matcher = pattern.matcher(s);

		while (matcher.find()) sCount++;

		System.out.println("Il testo contiene " + rCount + " righe, " + sCount + " frasi, " + wCount + " parole, " + s.length() + " caratteri.");
	}
}

