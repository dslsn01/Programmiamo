/* file Esercizio16.java */

import java.util.Arrays;

public class Esercizio16 {
	public static void main(String [] args) {
		int [] nums = {1, 3, 5, 7, 9};
		int val = 10;

		System.out.println(Arrays.toString(nums));

		for (int i = 0; i < nums.length; i++) {
			for (int j = i+1; j < nums.length; j++) {
				if (nums[i] + nums[j] == val) {
					System.out.println(nums[i] + " + " + nums[j] + " = " + val);
				}
			}
		}
	}
}

