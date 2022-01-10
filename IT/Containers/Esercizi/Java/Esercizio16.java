/* file Esercizio16.java */

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Esercizio16 {
	public static void main(String [] args) {
		Random rand = new Random();
		int r_size = (rand.nextInt(10) + 1) * 5;
		List<Integer> nums = new ArrayList<Integer>();

		for (int i = 0; i < r_size; i++) {
			nums.add(rand.nextInt(100) + 1);
		}

		Collections.sort(nums);
		System.out.println(nums);

		int i = nums.size() / 2;

		if (nums.size() % 2 != 0) {
			System.out.println("Mediana: " + nums.get(i) + ".");
		}
		else {
			int j = i-1;
			double mdn = ((double)nums.get(i) + nums.get(j)) / 2;
			System.out.println("Mediana: " + mdn + ".");
		}
	}
}

