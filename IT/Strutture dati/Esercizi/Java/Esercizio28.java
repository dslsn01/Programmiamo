/* file Esercizio28.java */

import java.util.Arrays;
import java.util.Random;

public class Esercizio28 {
	public static void main(String [] args) {
		Random rand = new Random();
		final int LEN = rand.nextInt(20) + 1;

		int [] nums = new int[LEN*5];

		for (int i = 0; i < nums.length; i++) {
			nums[i] = rand.nextInt(100) + 1;
		}

		Arrays.sort(nums);

		System.out.println(Arrays.toString(nums));

		double mdn = 0;
		int i = nums.length / 2;

		if (nums.length % 2 != 0) {
			mdn = nums[i];
		}
		else {
			int j = i-1;
			mdn = ((double) nums[j] + nums[i]) / 2;
		}

		System.out.println("Mediana: " + mdn + ".");
	}
}

