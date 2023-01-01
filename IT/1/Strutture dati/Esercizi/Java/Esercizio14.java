/* file Esercizio14.java */

import java.util.Arrays;
import java.util.Random;

public class Esercizio14 {
	public static void main(String [] args) {
		Random rand = new Random();
		int [] nums = new int[10];

		for (int i = 0; i < nums.length; i++) {
			int r = rand.nextInt(100) + 1;
			nums[i] = r;
		}

		System.out.println(Arrays.toString(nums));

		Arrays.sort(nums);

		System.out.println(Arrays.toString(nums));

		int maxIndex = nums.length - 1;
		System.out.println("Numero maggiore nell'array: " + nums[maxIndex]);

		int minIndex = 0;
		System.out.println("Numero minore nell'array: " + nums[minIndex]);
	}
}

