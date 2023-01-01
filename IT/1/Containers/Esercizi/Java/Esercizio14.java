/* file Esercizio14.java */

import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.Random;

public class Esercizio14 {
	public static void main(String [] args) {
		Random rand = new Random();
		List<Integer> nums = new ArrayList<Integer>();

		for (int i = 0; i < 10; i++) {
			int r = rand.nextInt(10) + 1;
			nums.add(r);
		}

		System.out.println("Lista originale: ");
		System.out.println(nums);

		Set<Integer> uniques = new HashSet<Integer>(nums);

		System.out.println("Lista senza elementi duplicati: ");
		System.out.println(uniques);
	}
}

