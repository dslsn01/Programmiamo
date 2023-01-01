/* file Esercizio19.java */

public class Esercizio19 {
	public static void main(String [] args) {
		String si = "1 234 567.89";
		String us = si.replace(" ", ",");
		String it = si.replace(".", ",").replace(" ", ".");

		System.out.println("Stile SI: " + si);
		System.out.println("Stile US: " + us);
		System.out.println("Stile IT: " + it);
	}
}

