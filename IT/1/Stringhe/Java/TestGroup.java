/* file TestGroup.java */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class TestGroup {
	public static void main(String [] args) {
		String s = "Via Roma 40, Milano, MI";

		String regex = "([\\w\\s]+),\\s([\\w]+),\\s([\\w]{2})";
		Pattern pattern = Pattern.compile(regex);
		Matcher matcher = pattern.matcher(s);

		while (matcher.find()) {
			System.out.println("Stringa completa: " + matcher.group());
			System.out.println("Indirizzo: " + matcher.group(1));
			System.out.println("Città: " + matcher.group(2));
			System.out.println("Provincia: " + matcher.group(3));
		}

		System.out.print(System.lineSeparator());

		s = "Nome: \"John\", cognome: \"Doe\", età: \"30\", indirizzo: \"ignoto\" segni particolari: \"\"";
		System.out.println(s);

		regex = "(['\"]).*?\\1";
		pattern = Pattern.compile(regex);
		matcher = pattern.matcher(s);

		while (matcher.find()) {
			System.out.println(matcher.group());
		}
	}
}

