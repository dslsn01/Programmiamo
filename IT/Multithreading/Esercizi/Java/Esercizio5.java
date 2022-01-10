/* file Esercizio5.java */

import java.util.Random;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

class Target implements Runnable {
	@Override
	public void run() {
		System.out.println("Ciao, mondo!");
	}
}

public class Esercizio5 {
	public static void main(String [] args) {
		Random randomizer = new Random(System.currentTimeMillis());
		// tra 2 e 10 thread
		int nThreads = randomizer.nextInt(9) + 2;
		System.out.println("Verrà creato un pool di " + nThreads + " thread.");

		ExecutorService threadPool = Executors.newFixedThreadPool(nThreads);

		for (int i = 0; i < nThreads; i++) {
			threadPool.submit(new Target());
		}

		threadPool.shutdown();
	}
}

