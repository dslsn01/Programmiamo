/* file Esercizio11.java */

import java.util.ArrayList;
import java.util.Collections;

public class Esercizio11 {
	public static void main(String [] args) {
		ArrayList<Integer> a = new ArrayList<Integer>();

		a.add(1);
		a.add(2);
		a.add(3);

		ArrayList<Integer> b = new ArrayList<Integer>();

		b.add(3);
		b.add(2);
		b.add(1);

		System.out.println("a = " + a);
		System.out.println("b = " + b);

		ArrayList<Integer> copy1 = new ArrayList<Integer>(a);
		ArrayList<Integer> copy2 = new ArrayList<Integer>(b);

		Collections.sort(copy1);
		Collections.sort(copy2);

		System.out.println("a e b contengono gli stessi elementi? " + copy1.equals(copy2));
	}
}

