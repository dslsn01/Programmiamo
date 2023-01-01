/* file Esercizio28.java */

import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;

public class Esercizio28 {
	static class EntryComparator implements Comparator<Entry<Integer, Integer>> {
		@Override
		public int compare(Entry<Integer, Integer> p1, Entry<Integer, Integer> p2) {
			return p1.getValue().compareTo(p2.getValue());
		}
	}

	public static void main(String [] args) {
		Map<Integer, Integer> nums = new HashMap<Integer, Integer>();

		nums.put(1, 7);
		nums.put(2, 5);
		nums.put(3, 3);

		System.out.println("Numeri = " + nums);

		Entry<Integer, Integer> max;
		max = Collections.max(nums.entrySet(), new EntryComparator());

		Entry<Integer, Integer> min;
		min = Collections.min(nums.entrySet(), new EntryComparator());

		System.out.println("Maggior valore nella mappa: " + max.getValue() + ", associato alla chiave " + max.getKey() + ".");
		System.out.println("Minor valore nella mappa: " + min.getValue() + ", associato alla chiave " + min.getKey()+ ".");
	}
}

