/* file Esercizio4.java */

import java.util.Random;

class Target implements Runnable {
	@Override
	public void run() {
		System.out.println("Ciao, mondo!");
	}
}

public class Esercizio4 {
	public static void main(String [] args) {
		Random randomizer = new Random(System.currentTimeMillis());
		// tra 2 e 10 thread
		int nThreads = randomizer.nextInt(9) + 2;
		System.out.println("Verranno creati " + nThreads + " thread.");

		for (int i = 0; i < nThreads; i++) {
			Thread t = new Thread(new Target());
			t.start();
		}
	}
}

