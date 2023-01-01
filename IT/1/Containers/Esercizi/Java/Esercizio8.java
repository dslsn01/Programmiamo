/* file Esercizio8.java */

import java.util.ArrayList;
import java.util.Random;

public class Esercizio8 {
	public static void main(String [] args) {
		ArrayList<Integer> nums = new ArrayList<Integer>();
		Random rand = new Random();

		for (int i = 0; i < 10; i++) {
			int r = rand.nextInt(100) + 1;
			nums.add(r);
		}

		System.out.println(nums);

		int min = nums.get(0);
		for (int i = 1; i < nums.size(); i++) {
			int n = nums.get(i);
			if (n < min) min = n;
		}

		System.out.println("Numero minore nella lista: " + min);
	}
}

