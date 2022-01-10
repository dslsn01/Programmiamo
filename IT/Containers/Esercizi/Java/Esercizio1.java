/* file Esercizio1.java */

import java.util.ArrayList;

public class Esercizio1 {
	public static void main(String [] args) {
		ArrayList<Integer> nums = new ArrayList<Integer>();

		nums.add(1);
		nums.add(3);
		nums.add(5);
		nums.add(7);
		nums.add(9);

		for (int i = 0; i < nums.size(); i++) {
			System.out.print(nums.get(i) + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

