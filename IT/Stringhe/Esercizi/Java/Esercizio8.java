/* file Esercizio8.java */

public class Esercizio8 {
	public static void main(String [] args) {
		String [] n = {"United States of America", "Unione delle Repubbliche Socialiste Sovietiche", "European Union"};

		for (String s : n) {
			StringBuilder acr = new StringBuilder();
			String [] tokens = s.split(" ");
			for (String t : tokens) {
				char i = t.charAt(0);
				if (Character.isUpperCase(i)) {
					acr.append(i + ".");
				}
			}

			System.out.println(acr.toString() + " (" + s + ")");
		}
	}
}

