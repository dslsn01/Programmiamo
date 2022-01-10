/* file Esercizio22.java */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio22 {
	public static void main(String [] args) {
		String s = "Nome: \"John\", cognome: \"Doe\", età: 32, indirizzo: \"ignoto\" numero di telefono: 333-1234567" + System.lineSeparator();
		s += "Nome: \"Paula\", cognome: \"Poe\", età: 30, numero di telefono: 320/1200100" + System.lineSeparator();
		s += "Nome: \"Joe\", cognome: \"Bloggs\", età: 35, numero di telefono: 02-987654" + System.lineSeparator();
		s += "Nome: \"Jane\", cognome: \"Doe\", indirizzo: \"?\" numero di telefono: 06/12345001";

		System.out.println(s);

		System.out.println("Numeri di telefono: ");

		String regex = "[\\d]{2,3}[-/]{1}[\\d]{5,8}";
		Pattern pattern = Pattern.compile(regex);
		Matcher matcher = pattern.matcher(s);

		while (matcher.find()) {
			System.out.println(matcher.group());
		}
	}
}

