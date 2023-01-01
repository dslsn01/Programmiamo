/* file Esercizio17.java */

import java.util.List;
import java.util.ArrayList;
import java.util.Random;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.util.Collections;
import java.util.Comparator;

public class Esercizio17 {
	public static void main(String [] args) {
		Random rand = new Random();
		int r_size = (rand.nextInt(10) + 1) * 5;
		List<Integer> nums = new ArrayList<Integer>();

		for (int i = 0; i < r_size; i++) {
			nums.add(rand.nextInt(100) + 1);
		}

		System.out.println(nums);

		int tot = 0;

		for (int m : nums) {
			tot += m;
		}

		Collections.sort(nums);

		double m = (double) tot / nums.size();

		System.out.println("Media: " + String.format("%.2f", m) + ".");

		int i = nums.size() / 2;

		if (nums.size() % 2 != 0) {
			System.out.println("Mediana: " + nums.get(i) + ".");
		}
		else {
			int j = i-1;
			double mdn = ((double)nums.get(i) + nums.get(j)) / 2;
			System.out.println("Mediana: " + mdn + ".");
		}

		Map<Integer, Integer> occurrences = new HashMap<Integer, Integer>();

		for (Integer n : nums) {
			int count = occurrences.containsKey(n) ? occurrences.get(n) : 0;
			occurrences.put(n, count+1);
		}

		List<Entry<Integer, Integer>> counts = new ArrayList<Entry<Integer, Integer>>(occurrences.entrySet());
		Collections.sort(counts, new Comparator<Entry<Integer, Integer>>() {
				@Override
				public int compare(Entry<Integer, Integer> a, Entry<Integer, Integer> b) {
					return b.getValue().compareTo(a.getValue());
				}
			}
		);

		int md = counts.get(0).getValue();

		if (md == 1) {
			System.out.println("La lista non ha una moda.");
			return;
		}

		System.out.print("Moda (" + md + " occorrenze): ");

		int j = 0;
		for (Entry<Integer, Integer> e : counts) {
			if (e.getValue() == md) {
				if (j > 0) System.out.print(", ");
				System.out.print(e.getKey());
				j++;
			}
		}

		System.out.println(".");
	}
}

