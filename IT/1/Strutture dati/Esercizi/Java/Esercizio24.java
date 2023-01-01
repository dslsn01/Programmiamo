/* file Esercizio24.java */

import java.util.Arrays;
import java.util.Random;

public class Esercizio24 {
	public static void main(String [] args) {
		Random rand = new Random();
		int [] nums = new int[20];

		for (int i = 0; i < nums.length; i++) {
			nums[i] = rand.nextInt(100) + 1;
		}

		System.out.println("Array originale: ");
		System.out.println(Arrays.toString(nums));

		int l = 0;
		int r = nums.length-1;

		for (int i = 0; i < nums.length; i++) {
			while (nums[l] % 2 == 0) l++;
			while (nums[r] % 2 != 0) r--;
			if (l < r) {
				int tmp = nums[r];
				nums[r] = nums[l];
				nums[l] = tmp;
			}
		}

		System.out.println("Array originale, numeri pari a destra, dispari a sinistra: ");
		System.out.println(Arrays.toString(nums));

		int [] p = Arrays.copyOfRange(nums, 0, l); // numeri pari
		Arrays.sort(p);

		System.out.println("Numeri pari (ordinati): ");
		System.out.println(Arrays.toString(p));

		int [] dp = Arrays.copyOfRange(nums, l, nums.length); // numeri dispari
		Arrays.sort(dp);

		System.out.println("Numeri dispari (ordinati): ");
		System.out.println(Arrays.toString(dp));
	}
}

