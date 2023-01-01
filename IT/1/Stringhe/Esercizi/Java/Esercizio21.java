/* file Esercizio21.java */

public class Esercizio21 {
	public static void main(String [] args) {
		String s = "Il rosso e il nero";
		String s2 = s.replaceAll("Il ([a-zA-Z]+) e il ([a-zA-Z]+)", "Il $2 e il $1");

		System.out.println(s);
		System.out.println(s2);
	}
}

