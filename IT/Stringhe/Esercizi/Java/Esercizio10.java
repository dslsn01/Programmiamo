/* file Esercizio10.java */

public class Esercizio10 {
	public static void main(String [] args) {
		String s = "Era pacifica pare";

		String s1 = s.replace(" ", "").toLowerCase();
		int l = s1.length();

		int o1 = l / 2;
		int o2 = l % 2 == 0 ? o1 : o1+1;

		String t1 = s1.substring(0, o1);

		StringBuilder sb = new StringBuilder(s1.substring(o2, s1.length()));
		String t2 = sb.reverse().toString();

		if (t1.equals(t2)) {
			System.out.println("La frase \"" + s + "\" è palindroma.");
		}
	}
}

