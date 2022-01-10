/* file Esercizio12.java */

import java.util.Arrays;
import java.util.Random;

public class Esercizio12 {
	public static void main(String [] args) {
		Random rand = new Random();
		int [] nums = new int[10];

		for (int i = 0; i < nums.length; i++) {
			int r = rand.nextInt(100) + 1;
			nums[i] = r;
		}

		System.out.println(Arrays.toString(nums));

		int m = nums[0];
		for (int i = 1; i < nums.length; i++) {
			int n = nums[i];
			if (n > m) m = n;
		}

		System.out.println("Numero maggiore nell'array: " + m);
	}
}

