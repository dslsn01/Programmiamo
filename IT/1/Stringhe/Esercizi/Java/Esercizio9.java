/* file Esercizio9.java */

public class Esercizio9 {
	public static boolean strEq(String s1, String s2) {
		int l = s1.length();
		if (l != s2.length()) return false;

		for (int i = 0; i < l; i++) {
			char c = s1.charAt(i);
			char c2 = s2.charAt(i);

			if (c != c2 && Character.toLowerCase(c) != Character.toLowerCase(c2)) {
				return false;
			}
		}

		return true;
	}

	public static void main(String [] args) {
		String s = "prìncipi";
		String [] ss = {"Prìncipi", "princìpi"};

		for (String t : ss) {
			if (strEq(s, t)) {
				System.out.println("Le parole \"" + s + "\" e \"" + t + "\" sono uguali.");
			}
			else {
				System.out.println("Le parole \"" + s + "\" e \"" + t + "\" sono diverse.");
			}
		}
	}
}

