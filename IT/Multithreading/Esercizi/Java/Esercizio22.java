/* file Esercizio22.java */

import java.util.Collections;
import java.util.Set;
import java.util.HashSet;

class PowerSet implements Runnable {
	private Set<Integer> set;
	private int start;
	private int end;
	private Set<Set<Integer>> powerSet;

	public PowerSet(Set<Integer> set, int start, int end, Set<Set<Integer>> powerSet) {
		this.set = set;
		this.start = start;
		this.end = end;
		this.powerSet = powerSet;
	}

	@Override
	public void run() {
		// String tName = Thread.currentThread().getName();
		Integer [] bits = (Integer[]) set.toArray(new Integer[set.size()]);
		// System.out.println(tName + " bits=" + Arrays.toString(bits));

		for (int i = start; i < end; i++) {
			// System.out.println(tName + " i=" + i + " start=" + start + " end=" + end);
			Set<Integer> subSet = new HashSet<>();
			for (int j = 0; j < bits.length; j++) {
				int mask = 1 << j;
				if ((i & mask) != 0) {
					subSet.add(bits[j]);
				}
			}
			// System.out.println(subSet);
			powerSet.add(subSet);
		}
	}
}

public class Esercizio22 {
	public static void main(String [] args) {
		Set<Integer> set = new HashSet<>();

		set.add(1);
		set.add(2);
		set.add(3);
		// set.add(4);
		// set.add(5);
		// set.add(6);
		// set.add(7);

		System.out.println(set);

		final int CARD_PSET = 1 << set.size(); // 2^n
		System.out.println("Cardinalità dell'insieme potenza: " + CARD_PSET);

		int nThreads = CARD_PSET / 2; // 4 threads

		int start = 0;
		int end = CARD_PSET / nThreads;

		Set<Set<Integer>> powerSet = Collections.synchronizedSet(new HashSet<Set<Integer>>());
		Thread [] threads = new Thread[nThreads];

		for (int i = 0, j = 2; i < nThreads; i++, j++) {
			threads[i] = new Thread(new PowerSet(set, start, end, powerSet));

			start = end;
			end = j * (CARD_PSET / nThreads);

			// System.out.println(i + ", start=" + start + ", end=" + end);
		}

		for (Thread t : threads) {
			t.start();
		}

		try {
			for (Thread t : threads) {
				t.join();
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println("Insieme potenza: ");
		System.out.println(powerSet);
		// System.out.println("Cardinalità " + powerSet.size());
	}
}

