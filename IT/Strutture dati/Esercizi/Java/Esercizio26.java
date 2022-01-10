/* file Esercizio26.java */

import java.util.Arrays;
import java.util.Random;

public class Esercizio26 {
	public static void main(String [] args) {
		Random rand = new Random();
		int [] nums = new int[10];

		for (int i = 0; i < nums.length; i++) {
			int r = rand.nextInt(10) + 1;
			nums[i] = r;
		}

		System.out.println("Array originale: ");
		System.out.println(Arrays.toString(nums));

		Arrays.sort(nums);

		System.out.println("Array ordinato: ");
		System.out.println(Arrays.toString(nums));

		int i = 0;
		int d = 0; // conteggio duplicati

		while (i < nums.length) {
			if (nums[i] != -1) {
				int n = nums[i];
				int j = i+1;
				while (j < nums.length && n == nums[j]) {
					nums[j] = -1;
					d++;
					j++;
				}
			}
			i++;
		}

		int [] uniques = new int[nums.length - d];

		for (int j = 0, k = 0; j < nums.length; j++) {
			if (nums[j] != -1) {
				uniques[k] = nums[j];
				k++;
			}
		}

		System.out.println("Array senza elementi duplicati: ");
		System.out.println(Arrays.toString(uniques));
	}
}

