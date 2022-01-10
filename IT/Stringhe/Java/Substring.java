/* file Substring.java */

public class Substring {
	public static void main(String [] args) {
		String s = "Ciao, mondo!";

		String s1 = s.substring(0, 6);
		String s2 = s.substring(6, s.length());

		System.out.println(s1);
		System.out.println(s2);
	}
}

