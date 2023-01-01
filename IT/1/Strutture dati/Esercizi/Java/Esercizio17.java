/* file Esercizio17.java */

import java.util.Arrays;

public class Esercizio17 {
	public static void main(String [] args) {
		int [] a = {1, 2, 3};
		int [] b = {3, 2, 1};

		System.out.println("a = " + Arrays.toString(a));
		System.out.println("b = " + Arrays.toString(b));

		Arrays.sort(a);
		Arrays.sort(b);

		System.out.println("a e b contengono gli stessi elementi? " + Arrays.equals(a, b));
	}
}

