/*
file Esercizio27.java
compilare con: javac -encoding utf8 Esercizio27.java
*/

import java.util.Arrays;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio27 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola (o una frase): ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		System.out.print("Controllando i caratteri: ");

		// usare il tipo Character, non il tipo char
		Character [] voc = {'a', 'à', 'e', 'è', 'i', 'ì', 'o', 'ò', 'u', 'ù'};
		int v = 0;

		for (char c : s.toCharArray()) {
			char nc = Character.toLowerCase(c);
			if (Arrays.asList(voc).contains(nc)) v++;
		}

		System.out.println("   -> la stringa \"" + s + "\" contiene " + v + " vocali.");

		System.out.print("Con le espressioni regolari: ");

		Pattern pattern = Pattern.compile("[aeiouÀ-ù]", Pattern.CASE_INSENSITIVE);
		Matcher matcher = pattern.matcher(s);

		v = 0;

		while (matcher.find()) v++;

		System.out.println("-> la stringa \"" + s + "\" contiene " + v + " vocali.");
	}
}

