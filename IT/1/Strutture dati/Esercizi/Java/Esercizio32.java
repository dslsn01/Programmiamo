/* file Esercizio32.java */

import java.util.Random;
import java.util.Arrays;

public class Esercizio32 {
	public static void main(String [] args) {
		Random rand = new Random();
		int [] nums = new int[10];

		for (int i = 0; i < nums.length; i++) {
			int r = rand.nextInt(100) + 1;
			nums[i] = r;
		}

		System.out.println("Array originale:");
		System.out.println(Arrays.toString(nums));

		int n = nums.length - 1;
		int lc = n;
		while (lc > 0) {
			lc = 0;
			for (int i = 0; i < n; i++) {
				int n1 = nums[i];
				int n2 = nums[i+1];
				// ordine decrescente
				if (n1 < n2) {
					nums[i] = n2;
					nums[i+1] = n1;
				}
				lc = i;
			}
			n = lc;
		}

		System.out.println("Array ordinato:");
		System.out.println(Arrays.toString(nums));
	}
}

