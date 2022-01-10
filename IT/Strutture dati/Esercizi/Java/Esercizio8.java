/* file Esercizio8.java */

import java.util.Arrays;

public class Esercizio8 {
	public static void main(String [] args) {
		int [] nums = {1, 3, 5, 7, 9};

		System.out.println(Arrays.toString(nums));

		int tot = 0;

		for (int n : nums) {
			tot += n;
		}

		System.out.println("Media matematica degli elementi: " + tot / nums.length);
	}
}

