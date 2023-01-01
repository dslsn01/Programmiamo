/* file Esercizio6.java */

import java.util.ArrayList;
import java.util.Collections;

public class Esercizio6 {
	public static void main(String [] args) {
		ArrayList<Integer> nums = new ArrayList<Integer>();

		nums.add(1);
		nums.add(3);
		nums.add(5);
		nums.add(7);
		nums.add(9);

		System.out.println(nums);

		Collections.reverse(nums);

		System.out.println(nums);
	}
}

