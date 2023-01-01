/* file Ex.java */

import java.util.Arrays;

public class Ex {
	public static void main(String [] args) {
		int [] sq = new int[10];

		for (int i = 0, j = 1; i < sq.length; i++, j++) {
			sq[i] = j*j;
		}

		System.out.println(Arrays.toString(sq));
	}
}

