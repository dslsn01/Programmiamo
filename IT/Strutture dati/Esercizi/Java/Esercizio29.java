/* file Esercizio29.java */

import java.util.Arrays;
import java.util.Random;

public class Esercizio29 {
	public static void main(String [] args) {
		Random rand = new Random();
		final int LEN = rand.nextInt(20) + 1;
		int [] nums = new int[LEN*5];

		for (int i = 0; i < nums.length; i++) {
			nums[i] = rand.nextInt(100) + 1;
		}

		System.out.println(Arrays.toString(nums));

		Arrays.sort(nums);

		System.out.println(Arrays.toString(nums));

		int md = 1;
		int [] counts = new int[nums.length];
		int i = 0;

		while (i < nums.length) {
			int n = nums[i];
			int j = i+1; // indice dell'elemento successivo
			int occ = 1;
			while (j < nums.length && n == nums[j]) {
				occ++;
				j++;
			}
			counts[i] = occ; // memorizza il numero di occorrenze
			if (occ > md) md = occ;
			i += occ; // salta al prossimo numero
		}

		if (md == 1) {
			System.out.println("L'array non presenta una moda.");
			return;
		}

		System.out.print("Moda (" + md + " occorrenze): ");

		int k = 0;
		for (int j = 0; j < counts.length; j++) {
			if (counts[j] == md) {
				if (k > 0) System.out.print(", ");
				System.out.print(nums[j]);
				k++;
			}
		}

		System.out.println(".");
	}
}

