/* file Esercizio10.java */

import java.util.Arrays;

public class Esercizio10 {
	public static void main(String [] args) {
		int [] nums = {1, 3, 5, 7, 9};
		int [] copy = new int[nums.length];

		for (int i = nums.length - 1, j = 0; i >= 0; i--, j++) {
			copy[j] = nums[i];
		}

		System.out.println(Arrays.toString(nums));
		System.out.println(Arrays.toString(copy));
	}
}

