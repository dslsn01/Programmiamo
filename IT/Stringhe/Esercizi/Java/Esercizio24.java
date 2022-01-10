/* file Esercizio24.java */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio24 {
	public static void main(String [] args) {
		System.out.println("********************* Cambia la password *********************");
		System.out.println("La password deve contenere un minimo di otto caratteri, inclusa una maiuscola, un numero e un simbolo speciale.");
		String pwd = "";

		String r = "^(.{0,7}|[^\\d]*|[^a-zà-ù]*|[^A-ZÀ-Ù]*|[a-zA-ZÀ-ù0-9]*)$";
		Pattern pattern = Pattern.compile(r);

		while (pwd.isEmpty()) {
			String s = System.console().readLine("Digita la nuova password: ");
			if (!pattern.matcher(s).matches()) {
				pwd = s;
				System.out.println("Nuova password salvata.");
			}
			else {
				System.out.println("Password non valida!");
			}
		}
	}
}

