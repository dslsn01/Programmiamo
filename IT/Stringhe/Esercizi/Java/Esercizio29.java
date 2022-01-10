/* file Esercizio29.java */

public class Esercizio29 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una parola (o una frase): ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		String s1 = s.replace("[^a-zA-ZÀ-ù]", "");

		if (s1.isEmpty()) {
			System.out.println("La stringa \"" + s + "\" non contiene caratteri alfabetici!");
			return;
		}

		System.out.print("Controllando i caratteri: ");

		int size = s1.length();
		int lcount = 0;
		int ucount = 0;
		char [] arr = s1.toCharArray();

		for (char c : arr) {
			if (Character.isLowerCase(c)) lcount++;
			else ucount++;
		}

		if (ucount == size) {
			System.out.println("   -> la stringa \"" + s + "\" contiene solo caratteri maiuscoli.");
		}
		else if (lcount == size) {
			System.out.println("   -> la stringa \"" + s + "\" contiene solo caratteri minuscoli.");
		}
		else {
			System.out.println("   -> la stringa \"" + s + "\" contiene caratteri maiuscoli e minuscoli.");
		}

		System.out.print("Con le espressioni regolari: ");

		if (s1.matches("^[^a-zà-ù]+$")) {
			System.out.println("-> la stringa \"" + s + "\" contiene solo caratteri maiuscoli.");
		}
		else if (s1.matches("^[^A-ZÀ-Ù]+$")) {
			System.out.println("-> la stringa \"" + s + "\" contiene solo caratteri minuscoli.");
		}
		else {
			System.out.println("-> la stringa \"" + s + "\" contiene caratteri maiuscoli e minuscoli.");
		}
	}
}

