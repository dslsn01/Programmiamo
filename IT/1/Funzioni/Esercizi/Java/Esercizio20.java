/* file Esercizio20.java */

import java.util.Arrays;

public class Esercizio20 {
	static double avg(int [] arr) {
		int tot = 0;
		for (int n : arr) {
			tot += n;
		}

		return (double) tot / arr.length;
	}

	public static void main(String [] arr) {
		int [] arr1 = new int[] {1, 7, 13};
		int [] arr2 = new int[] {4, 9, 17, 33, 39};
		System.out.println("Media tra 1, 7, 13 = " + avg(arr1));
		System.out.println("Media tra 4, 9, 17, 33, 39 = " + avg(arr2));
	}
}

