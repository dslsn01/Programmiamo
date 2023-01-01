/* file Sorting3.java */

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class PairComparator implements Comparator<Pair> {
	public int compare(Pair p1, Pair p2) {
		return p1.getA().compareTo(p2.getA());
	}
}

public class Sorting3 {
	public static void main(String [] args) {
		/* crea una lista di coppie 'Pair' */

		List<Pair> arr = new ArrayList<Pair>();

		arr.add(new Pair(7, 'K'));
		arr.add(new Pair(5, 'M'));
		arr.add(new Pair(3, 'B'));
		arr.add(new Pair(1, 'R'));
		arr.add(new Pair(6, 'Y'));
		arr.add(new Pair(4, 'C'));
		arr.add(new Pair(2, 'G'));

		System.out.println(arr);

		PairComparator cmp = new PairComparator();

		Collections.sort(arr, cmp);

		System.out.println(arr);
	}
}

