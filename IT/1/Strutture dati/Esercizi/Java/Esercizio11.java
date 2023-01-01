/* file Esercizio11.java */

import java.util.Arrays;

public class Esercizio11 {
	public static void main(String [] args) {
		int [] nums = {1, 3, 5, 7, 9};

		System.out.println(Arrays.toString(nums));

		// inverte l'array originale

		for (int i = 0, j = nums.length-1; i < nums.length / 2; i++, j--) {
			int z = nums[j];
			nums[j] = nums[i];
			nums[i] = z;
		}

		System.out.println(Arrays.toString(nums));
	}
}

