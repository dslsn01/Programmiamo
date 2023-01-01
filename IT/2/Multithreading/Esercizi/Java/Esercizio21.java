/* file Esercizio21.java */

import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Sieve implements Runnable {
	private int [] numbers;
	private List<Integer> primes;

	public Sieve(int [] numbers, List<Integer> primes) {
		this.numbers = numbers;
		this.primes = primes;
	}

	@Override
	public void run() {
		for (int i = 0; i < numbers.length; i++) {
			int n = numbers[i];
			boolean isPrime = true;
			for (int j = 2; j < Math.floor(Math.sqrt(n))+1; j++) {
				if (n % j == 0) {
					isPrime = false;
					break;
				}
			}

			if (isPrime == true) {
				primes.add(n);
			}
		}
	}
}

public class Esercizio21 {
	public static void main(String [] args) {
		int n = 0;

		while (n < 2) {
			try {
				n = Integer.parseInt(System.console().readLine("Inserisci un numero naturale >= 2: "));
			}
			catch (NumberFormatException e) {
				System.err.println("Numero non valido!");
			}
		}

		final int N = n-1; // escludiamo 1 (non primo per definizione)

		int nThreads = n > 8 ? 4 : 1;
		int lSection = N / nThreads;
		if (N % nThreads > 0) nThreads++;

		int start = 0;
		int end = start + lSection;

		int [] numbers = new int[N];
		for (int i = 0, j = 2; i < N; i++, j++) {
			numbers[i] = j;
		}

		// System.out.println(Arrays.toString(numbers));

		List<Integer> primes = Collections.synchronizedList(new ArrayList<Integer>());
		Thread [] workers = new Thread[nThreads];

		for (int i = 0; i < nThreads; i++) {
			int [] tmp = Arrays.copyOfRange(numbers, start, end);
			// System.out.println("tmp: " + Arrays.toString(tmp));

			workers[i] = new Thread(new Sieve(tmp, primes));

			start = end;
			if (start + lSection < N) {
				end = start + lSection;
			}
			else {
				end = N;
			}
		}

		long startT = System.currentTimeMillis();

		for (Thread t : workers) {
			t.start();
		}

		try {
			for (Thread t : workers) {
				t.join();
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		long endT = System.currentTimeMillis();

		// tempo totale in millisecondi
		System.out.println("Tempo totale: " + (endT - startT) + " millisecondi.");

		int nPrimes = primes.size();
		System.out.println("Ci sono " + nPrimes + " numeri primi minori o uguali a " + n + ".");

		if (nPrimes <= 100) {
			Collections.sort(primes);
			System.out.println(primes);
		}
	}
}

