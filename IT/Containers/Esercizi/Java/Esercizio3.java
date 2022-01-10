/* file Esercizio3.java */

import java.util.ArrayList;

public class Esercizio3 {
	public static void main(String [] args) {
		ArrayList<Integer> nums = new ArrayList<Integer>();

		nums.add(1);
		nums.add(3);
		nums.add(5);
		nums.add(7);
		nums.add(9);

		for (int n : nums) {
			System.out.print(n + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

