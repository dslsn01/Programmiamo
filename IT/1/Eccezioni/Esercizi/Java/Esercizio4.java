/* file Esercizio4.java */

import java.util.Arrays;

public class Esercizio4 {
	public static void main(String [] args) {
		String [] nums = {"1", "2", "", "3", "abc", "7", "def"};
		System.out.println(Arrays.toString(nums));

		int tot = 0;

		try {
			for (String n : nums) {
				tot += Integer.parseInt(n);
			}
		}
		catch (NumberFormatException e) {
			System.out.println(e.getMessage());
		}

		System.out.println("Somma dei numeri presenti: " + tot);
		System.out.println("Fine del programma.");
	}
}

