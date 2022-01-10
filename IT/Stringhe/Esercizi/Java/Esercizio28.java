/*
file Esercizio28.java
compilare con: javac -encoding utf8 Esercizio28.java
*/

import java.util.Arrays;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio28 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola (o una frase): ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		System.out.print("Controllando i caratteri: ");

		// usare il tipo Character, non il tipo char
		Character [] voc = {'a', 'à', 'e', 'è', 'i', 'ì', 'o', 'ò', 'u', 'ù'};
		int cons = 0;

		for (char c : s.toCharArray()) {
			// salta punteggiatura, spazi, simboli speciali...
			if (!Character.isLetter(c)) continue;
			char nc = Character.toLowerCase(c);
			if (!Arrays.asList(voc).contains(nc)) cons++;
		}

		System.out.println("   -> la stringa \"" + s + "\" contiene " + cons + " consonanti.");

		System.out.print("Con le espressioni regolari: ");

		cons = 0;

		// elimina punteggiatura, spazi, simboli speciali...

		String st = s.replaceAll("[^À-ùa-zA-Z]", "");

		if (!st.isEmpty()) {
			// esclude tutto ciò che non è una vocale
			Pattern pattern = Pattern.compile("[^À-ùaeiou]", Pattern.CASE_INSENSITIVE);
			Matcher matcher = pattern.matcher(st);

			while (matcher.find()) cons++;
		}

		System.out.println("-> la stringa \"" + s + "\" contiene " + cons + " consonanti.");
	}
}

