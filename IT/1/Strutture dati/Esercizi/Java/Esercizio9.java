/* file Esercizio9.java */

import java.util.Arrays;

public class Esercizio9 {
	public static void main(String [] args) {
		int [] nums = {1, 3, 5, 7, 9};

		int [] copy = Arrays.copyOfRange(nums, 0, nums.length);

		System.out.println(Arrays.toString(nums));
		System.out.println(Arrays.toString(copy));
	}
}

