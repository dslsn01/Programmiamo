/* file Esercizio13.java */

import java.util.ArrayList;
import java.util.Random;

public class Esercizio13 {
	public static void main(String [] args) {
		ArrayList<Integer> nums = new ArrayList<Integer>();

		Random rand = new Random();

		for (int i = 0; i < 20; i++) {
			nums.add(rand.nextInt(100) + 1);
		}

		System.out.println(nums);

		ArrayList<Integer> p = new ArrayList<Integer>();	// numeri pari
		ArrayList<Integer> dp = new ArrayList<Integer>();	// numeri dispari

		for (int n : nums) {
			if (n % 2 == 0) p.add(n);
			else dp.add(n);
		}

		System.out.println("Numeri pari:");
		System.out.println(p);
		System.out.println("Numeri dispari:");
		System.out.println(dp);
	}
}

