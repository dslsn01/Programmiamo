/* file Esercizio4.java */

import java.util.ArrayList;

public class Esercizio4 {
	public static void main(String [] args) {
		ArrayList<Integer> nums = new ArrayList<Integer>();

		nums.add(1);
		nums.add(3);
		nums.add(5);
		nums.add(7);
		nums.add(9);

		System.out.println(nums);

		int tot = 0;

		for (int n : nums) {
			tot += n;
		}

		System.out.println("Somma degli elementi: " + tot);
	}
}

