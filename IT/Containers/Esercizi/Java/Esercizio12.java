/* file Esercizio12.java */

import java.util.ArrayList;
import java.util.Collections;

public class Esercizio12 {
	public static void main(String [] args) {
		ArrayList<Integer> a = new ArrayList<Integer>();

		a.add(1);
		a.add(2);
		a.add(3);

		ArrayList<Integer> b = new ArrayList<Integer>();

		b.add(3);
		b.add(2);
		b.add(1);

		ArrayList<Integer> c = new ArrayList<Integer>();

		c.add(1);
		c.add(2);
		c.add(3);

		System.out.println("a = " + a);
		System.out.println("b = " + b);
		System.out.println("c = " + c);

		System.out.println("a e b sono uguali? " + a.equals(b));
		System.out.println("a e c sono uguali? " + a.equals(c));
	}
}

