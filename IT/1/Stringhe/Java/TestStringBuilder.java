/* file TestStringBuilder.java */

public class TestStringBuilder {
	public static void main(String [] args) {
		/* crea un nuovo StringBuilder modificabile */

		StringBuilder sb = new StringBuilder();

		System.out.println("Scrivi una o più parole o frasi (stringa vuota per uscire).");

		while (true) {
			String s = System.console().readLine();
			if (s.isEmpty()) break;

			sb.append(s);

			// se necessario, aggiunge uno spazio vuoto
			char last = s.charAt(s.length()-1);
			if (!Character.isWhitespace(last)) {
				sb.append(" ");
			}
		}

		/* converte lo StringBuilder in una stringa immutabile */
		String s = sb.toString();
		System.out.println(s);
	}
}

