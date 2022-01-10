/* file Esercizio5.java */

import java.util.Arrays;

public class Esercizio5 {
	public static void main(String [] args) {
		String [] nums = {"1", "2", "", "3", "abc", "7", "def"};

		int tot = 0;

		for (String n : nums) {
			try {
				tot += Integer.parseInt(n);
			}
			catch (NumberFormatException e) {
				System.out.println(e.getMessage());
			}
		}

		System.out.println("Somma dei numeri presenti: " + tot);
		System.out.println("Fine del programma.");
	}
}

