/* file Esercizio18.java */

import java.util.Arrays;

public class Esercizio18 {
	public static void main(String [] args) {
		int [] a = {1, 2, 3};
		int [] b = {3, 2, 1};
		int [] c = {1, 2, 3};

		System.out.println("a = " + Arrays.toString(a));
		System.out.println("b = " + Arrays.toString(b));
		System.out.println("c = " + Arrays.toString(c));

		System.out.println("a e b sono uguali? " + Arrays.equals(a, b));
		System.out.println("a e c sono uguali? " + Arrays.equals(a, c));
	}
}

