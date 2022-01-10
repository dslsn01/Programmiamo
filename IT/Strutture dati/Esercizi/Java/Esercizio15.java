/* file Esercizio15.java */

import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

public class Esercizio15 {
	public static void main(String [] args) {
		Random rand = new Random();
		// dobbiamo usare il tipo "Integer" per utilizzare i metodi della classe Collection
		Integer [] nums = new Integer[10];

		for (int i = 0; i < nums.length; i++) {
			int r = rand.nextInt(100) + 1;
			nums[i] = r;
		}

		System.out.println(Arrays.toString(nums));

		Arrays.sort(nums, Collections.reverseOrder());

		System.out.println(Arrays.toString(nums));

		int maxIndex = 0;
		System.out.println("Numero maggiore nell'array: " + nums[maxIndex]);

		int minIndex = nums.length - 1;
		System.out.println("Numero minore nell'array: " + nums[minIndex]);
	}
}

