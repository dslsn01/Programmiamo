/* file Esercizio10.java */

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Esercizio10 {
	public static void main(String [] args) {
		ArrayList<Integer> nums = new ArrayList<Integer>();
		Random rand = new Random();

		for (int i = 0; i < 10; i++) {
			int r = rand.nextInt(100) + 1;
			nums.add(r);
		}

		System.out.println("Lista originale:");
		System.out.println(nums);

		Collections.sort(nums, Collections.reverseOrder());

		System.out.println("Lista ordinata:");
		System.out.println(nums);

		int maxIndex = 0;
		System.out.println("Numero maggiore in lista: " + nums.get(maxIndex));

		int minIndex = nums.size() - 1;
		System.out.println("Numero minore in lista: " + nums.get(minIndex));
	}
}

