/* file Esercizio2.java */

import java.util.ArrayList;

public class Esercizio2 {
	public static void main(String [] args) {
		ArrayList<Integer> nums = new ArrayList<Integer>();

		nums.add(1);
		nums.add(3);
		nums.add(5);
		nums.add(7);
		nums.add(9);

		for (int i = nums.size()-1; i >= 0; i--) {
			System.out.print(nums.get(i) + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

