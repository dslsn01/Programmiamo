/* file Esercizio25.java */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio25 {
	public static void main(String [] args) {
		String cod = "";

		String r = "^[A-Z]{6}[\\d]{2}[ABCDEHLMPRST]{1}(?:0[1-9]|[1-6][\\d]|7[01])[A-Z0-9]{4}[A-Z]{1}$";
		Pattern pattern = Pattern.compile(r);

		while (cod.isEmpty()) {
			String s = System.console().readLine("Digita il tuo codice fiscale: ");
			if (pattern.matcher(s).matches()) {
				cod = s;
				System.out.println("Codice fiscale corretto.");
			}
			else {
				System.out.println("Codice fiscale non valido!");
			}
		}
	}
}

