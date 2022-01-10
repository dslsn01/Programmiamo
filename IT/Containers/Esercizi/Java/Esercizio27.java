/* file Esercizio27.java */

import java.util.Map;
import java.util.HashMap;
import java.util.Collections;

public class Esercizio27 {
	public static void main(String [] args) {
		Map<Integer, Integer> nums = new HashMap<Integer, Integer>();

		nums.put(1, 7);
		nums.put(2, 5);
		nums.put(3, 3);

		System.out.println("Numeri = " + nums);

		Integer maxKey = Collections.max(nums.keySet());
		System.out.println("Chiave maggiore nella mappa: " + maxKey + ", associata al valore " + nums.get(maxKey) + ".");

		Integer minKey = Collections.min(nums.keySet());
		System.out.println("Chiave minore nella mappa: " + minKey + ", associata al valore " + nums.get(minKey) + ".");
	}
}

