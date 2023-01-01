/* file Esercizio3.java */

public class Esercizio3 {
	public static void main(String [] args) {
		int [] nums = {1, 3, 5, 7, 9};

		int i = nums.length - 1;

		while (i >= 0) {
			System.out.print(nums[i] + " ");
			i--;
		}

		System.out.print(System.lineSeparator());
	}
}

