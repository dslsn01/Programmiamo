/* file Esercizio25.java */

import java.util.Arrays;
import java.util.Random;

public class Esercizio25 {
	public static void main(String [] args) {
		Random rand = new Random();
		int [] nums = new int[10];

		for (int i = 0; i < nums.length; i++) {
			int r = rand.nextInt(10) + 1;
			nums[i] = r;
		}

		System.out.println("Array originale: ");
		System.out.println(Arrays.toString(nums));

		boolean dupl[] = new boolean[nums.length];
		int d = 0;

		for (int i = 0; i < nums.length; i++) {
			for (int j = i+1; j < nums.length; j++) {
				// duplicato trovato per la prima volta
				if (nums[i] == nums[j] && !dupl[j]) {
					dupl[j] = true;
					d++;
				}
			}
		}

		int [] uniques = new int[nums.length - d];
		for (int i = 0, j = 0; i < dupl.length; i++) {
			if (dupl[i] == false) {
				uniques[j] = nums[i];
				j++;
			}
		}

		System.out.println("Array senza elementi duplicati: ");
		System.out.println(Arrays.toString(uniques));
	}
}

