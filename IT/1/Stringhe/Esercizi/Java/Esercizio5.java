/* file Esercizio5.java */

public class Esercizio5 {
	public static void main(String [] args) {
		StringBuilder sb = new StringBuilder("Ciao, mondo!");
		String s = sb.reverse().toString();

		for (int i = 0; i < s.length(); i++) {
			System.out.print(s.charAt(i));
		}

		System.out.print(System.lineSeparator());
	}
}

