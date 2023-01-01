/* file Esercizio27.java */

import java.util.Arrays;
import java.util.Random;

public class Esercizio27 {
	public static void main(String [] args) {
		Random rand = new Random();
		int [] nums = new int[100];

		for (int i = 0; i < nums.length; i++) {
			nums[i] = rand.nextInt(100); // numero casuale da 0 a 99
		}

		System.out.println(Arrays.toString(nums));

		int md = 1;
		int [] counts = new int[nums.length];

		for (int i = 0; i < counts.length; i++) {
			int c = nums[i];
			counts[c]++;
			if (counts[c] > md) {
				md = counts[c];
			}
		}

		if (md == 1) {
			System.out.println("L'array non presenta una moda.");
			return;
		}

		System.out.print("Moda (" + md + " occorrenze): ");

		int j = 0;
		for (int i = 0; i < counts.length; i++) {
			if (counts[i] == md) {
				if (j > 0) System.out.print(", ");
				System.out.print(i);
				j++;
			}
		}

		System.out.print(System.lineSeparator());
	}
}

